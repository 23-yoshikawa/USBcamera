#include "imshow/imshow.hpp"
#include <rclcpp/rclcpp.hpp>

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Imshow>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}