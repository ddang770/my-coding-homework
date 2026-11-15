import java.util.Scanner;
public class DiemThi {
	//Viet phuong thuc nhap diem
	static double nhapDiem (Scanner sc, String mon) {
		double d;
		do {
			System.out.print("Diem" + mon + "(0-10): ");
			d = sc.nextDouble();
			if (d<0 || d > 10)
				System.out.println("Ko hop le, moi nhap lai");

		} while (d < 0 || d > 10);
		return d;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double toan = nhapDiem(sc,"Toan");
		double ly = nhapDiem(sc,"Ly");
		double hoa = nhapDiem(sc,"Hoa");
		double tong = toan + ly + hoa;
		double tb = tong/3;
		String xepLoai;
		if (tb >= 8.0)	xepLoai = "Gioi";
		else if (tb >= 6.5)	xepLoai = "Kha";
		else if (tb >= 5.0)	xepLoai = "Trung binh";
		else 				xepLoai = "Yeu";
		//In ket qua
		System.out.printf("Tong diem : %.1f / 30%n", tong);
		System.out.printf("Diem TB: %.2f%n", tb);
		System.out.printf("Xep loai: %s%n", xepLoai);
	}
}