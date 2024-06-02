#include "my_image_receiver_cpp_package/image_receiver_node.hpp"
#include <rclcpp/rclcpp.hpp>

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ImageReceiverNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
