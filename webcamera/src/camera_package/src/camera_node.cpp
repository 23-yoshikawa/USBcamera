#include "camera_package/camera_node.hpp"

CameraNode::CameraNode() : Node("camera_node")
{
    publisher_ = image_transport::create_publisher(this, "camera/image");

    // Open the default camera
    cap_.open(0); // 0 is typically the default camera index

    if (!cap_.isOpened())
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to open camera");
        return;
    }

    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100),
        std::bind(&CameraNode::timer_callback, this));
}

void CameraNode::timer_callback()
{
    cv::Mat frame;
    cap_ >> frame; // Capture frame from camera
    if (!frame.empty())
    {
        auto msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
        publisher_.publish(msg);
    }
}