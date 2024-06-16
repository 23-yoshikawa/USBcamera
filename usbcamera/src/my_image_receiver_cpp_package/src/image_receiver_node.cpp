#include "my_image_receiver_cpp_package/image_receiver_node.hpp"

ImageReceiverNode::ImageReceiverNode() : Node("image_receiver_node")
{
    subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        "camera/image", 10, std::bind(&ImageReceiverNode::image_callback, this, std::placeholders::_1));
}

void ImageReceiverNode::image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
{
    try
    {
        cv::Mat bgr_frame = cv_bridge::toCvCopy(msg, "bgr8")->image;
        cv::Mat hsv_frame;
        cv::cvtColor(bgr_frame, hsv_frame, cv::COLOR_BGR2HSV);
        cv::imshow("Received HSV Image", hsv_frame);
        cv::waitKey(1);
    }
    catch (cv_bridge::Exception &e)
    {
        RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
        return;
    }
}