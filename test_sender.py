from sender import *
import mock


def test_battery():
    dummy_battery = Battery()
    assert (dummy_battery.get_charge() == 99)
    assert (dummy_battery.get_charge() == 98)
    assert (20 < dummy_battery.get_temperature() < 45)
    assert (20 < dummy_battery.get_temperature() < 45)


def test_charge_sensor():
    dummy_battery = Battery()
    dummy_charge_sensor = ChargeSensor(dummy_battery)
    assert (dummy_charge_sensor.get_charge_level() == 99)
    assert (dummy_charge_sensor.get_charge_level() == 98)


def test_heat_sensor():
    dummy_battery = Battery()
    dummy_heat_sensor = HeatSensor(dummy_battery)
    assert (20 <= dummy_heat_sensor.get_temp_level() < 45)
    assert (20 <= dummy_heat_sensor.get_temp_level() < 45)


def test_sender():
    mock_charge_sensor = mock.Mock()
    mock_heat_sensor = mock.Mock()
    mock_receiver = mock.Mock()
    send_battery_params(mock_charge_sensor, mock_heat_sensor, mock_receiver)

    assert(mock_charge_sensor.get_charge_level.call_count == 50)
    assert(mock_heat_sensor.get_temp_level.call_count == 50)
    assert(mock_receiver.call_count == 50)


test_battery()
test_heat_sensor()
test_charge_sensor()
test_sender()
