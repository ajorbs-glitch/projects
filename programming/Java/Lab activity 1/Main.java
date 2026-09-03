package labAct1;

public class Main {

		public static void main(String[] args) {
			
			Book Ang_Kababalaghan_ng_Kalan = new Book(
					"Ang Kababalaghan ng Kalan",
					"Manuel Mansanitas",
					"Mythology",
					1975,
					67.50
					);
			
			Book Lingkod_Kaban = new Book(
					"Lingkod Kalan",
					"Ronda Maritonda",
					"History",
					2008,
					148.99
					);
			
			System.out.println("-- Book 1: " + Ang_Kababalaghan_ng_Kalan.title + "--");
			Ang_Kababalaghan_ng_Kalan.displayInfo();
			System.out.println();
			Ang_Kababalaghan_ng_Kalan.applyDiscount(10);
			
			System.out.println("-- Book 2: " + Lingkod_Kaban.title + "--");
			Lingkod_Kaban.displayInfo();
			System.out.println();
			Lingkod_Kaban.applyDiscount(30);
			
			System.out.println();
			System.out.println("Submitted by: Anthony Josh Orbiso");
			System.out.println("Section: CKHX1");
		}
}
