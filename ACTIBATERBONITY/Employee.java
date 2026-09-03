package ACTIBATERBONITY;

public class Employee {
	private String name;
	private float rate;
	private float hours;
	
	public Employee(String name, float rate, float hours) {
		this.name = name;
		this.rate = rate;
		this.hours = hours;
	}
	
	public double calculateRegularPay() {
		if (hours <= 40) {
			return rate * hours;
		} else {
			return rate * 40;
		}
	}
	
	public double calculateOvertimePay() {
		if (hours > 40) {
			return (hours - 40) * rate * 1.5;
		} else {
			return 0;
		}
	}
	
	public double calculateSalary() {
		return calculateRegularPay() + calculateOvertimePay();
	}
	
	public void displayEmployeeInfo() {
		System.out.println("\nEmployee Name: " + name);
		System.out.printf("Hourly Rate: %.2f%n", rate);
		System.out.printf("Hours Worked: %.2f%n", hours);
		
		System.out.printf("%nRegular Pay: %.2f%n",  calculateRegularPay());
		System.out.printf("Overtime Pay: %.2f%n", calculateOvertimePay());
		System.out.printf("Total Salary: %.2f%n", calculateSalary());
		
	}
	
}

