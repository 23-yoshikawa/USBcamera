#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <image_transport/image_transport.hpp>
#include <opencv2/opencv.hpp>

class CameraNode : public rclcpp::Node
{
public:
    CameraNode();

private:
    void timer_callback();

    image_transport::Publisher publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    cv::VideoCapture cap_{0}; // Open default camera
}