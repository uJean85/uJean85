#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

/**
 * @brief ROS2 Node to control a linear actuator for robotaxi doors.
 * 
 * This node subscribes to a topic ("door_actuator_cmd") to receive commands:
 * - "open": Move actuator forward to open the door.
 * - "close": Move actuator backward to close the door.
 * 
 * Replace the actuator control logic with your hardware-specific implementation.
 */
class DoorActuatorNode : public rclcpp::Node
{
public:
    DoorActuatorNode() : Node("door_actuator_node")
    {
        // Subscribe to actuator command topic
        actuator_cmd_sub_ = this->create_subscription<std_msgs::msg::String>(
            "door_actuator_cmd", 10,
            std::bind(&DoorActuatorNode::actuator_cmd_callback, this, std::placeholders::_1)
        );
        RCLCPP_INFO(this->get_logger(), "Door Actuator Node started.");
    }

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr actuator_cmd_sub_;

    /**
     * @brief Callback for actuator command messages.
     * @param msg The received command message ("open" or "close").
     */
    void actuator_cmd_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        if (msg->data == "open") {
            RCLCPP_INFO(this->get_logger(), "Opening door...");
            move_actuator_forward();
        } else if (msg->data == "close") {
            RCLCPP_INFO(this->get_logger(), "Closing door...");
            move_actuator_backward();
        } else {
            RCLCPP_WARN(this->get_logger(), "Unknown command: '%s'", msg->data.c_str());
        }
    }

    /**
     * @brief Move actuator forward (open door).
     * Replace with hardware-specific code.
     */
    void move_actuator_forward()
    {
        // TODO: Implement actuator forward movement
        RCLCPP_INFO(this->get_logger(), "[Simulated] Actuator moving forward.");
        // Example: digitalWrite(FORWARD_PIN, HIGH);
    }

    /**
     * @brief Move actuator backward (close door).
     * Replace with hardware-specific code.
     */
    void move_actuator_backward()
    {
        // TODO: Implement actuator backward movement
        RCLCPP_INFO(this->get_logger(), "[Simulated] Actuator moving backward.");
        // Example: digitalWrite(BACKWARD_PIN, HIGH);
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DoorActuatorNode>());
    rclcpp::shutdown();
    return 0;
}