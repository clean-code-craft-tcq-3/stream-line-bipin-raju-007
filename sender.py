import random


class Battery:
    charge_level = 100

    def get_charge(self):
        self.charge_level -= 1
        return self.charge_level

    def get_temperature(self):
        return random.randint(20, 45)


class ChargeSensor:
    def __init__(self, battery):
        self.battery = battery

    def get_charge_level(self):
        return self.battery.get_charge()


class HeatSensor:
    def __init__(self, battery):
        self.battery = battery

    def get_temp_level(self):
        return self.battery.get_temperature()


def send_battery_params(charge_sensor, heat_sensor, receiver):
    """
    Will send a string in csv format with battery params in the following format: '<battery_charge>, <battery_temp>'
    to the receiver function, where each new line is a new value.
    :param charge_sensor: Sensor that tells level of charge in battery
    :param heat_sensor: Sensor that tells level of battery heat
    :param receiver: Function where the string values are sent to store/print/test/etc.
    """
    for i in range(50):
        receiver(f"{charge_sensor.get_charge_level()}, {heat_sensor.get_temp_level()}")


def print_on_console(battery_params):
    print(battery_params)


if __name__ == '__main__':
    my_battery = Battery()
    my_charge_sensor = ChargeSensor(my_battery)
    my_heat_sensor = HeatSensor(my_battery)
    send_battery_params(my_charge_sensor, my_heat_sensor, print_on_console)
    print_on_console(battery_params)
