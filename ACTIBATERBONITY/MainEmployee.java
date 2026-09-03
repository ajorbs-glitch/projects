package ACTIBATERBONITY;

import java.util.Scanner;

public class MainEmployee {
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter Employee Name: ");
		String name = input.nextLine();
		
		System.out.print("Enter Hourly Rate: ");
		float rate = input.nextFloat();
		
		System.out.print("Enter Hours Worked: ");
		float hours = input.nextFloat();
		
		Employee employee = new Employee(name, rate, hours);
		
		employee.displayEmployeeInfo();
		
		input.close();
	}

}
