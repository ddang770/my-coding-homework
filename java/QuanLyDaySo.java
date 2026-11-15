import java.util.Scanner;

public class QuanLyDaySo{
	public static void inDaySo(int[] a){
		for (int i=0;i<a.length;i++)
			System.out.print(a[i]+" ");
		System.out.println();
	}

	public static void tongVaTrungBinhCong(int[] a){
		int sum = 0;
		for (int i=0;i<a.length;i++)
			sum+=a[i];
		double tbc= (double) sum/a.length;
		System.out.println("Tong: "+ sum);
		System.out.println("Trung binh cong: "+ tbc);
	}

	public static void soMaxMin(int[] a){
		int max,min;
		max=min=a[0];
		for(int i=0;i<a.length;i++){
			if(a[i]>max)
				max=a[i];
			if(a[i]<min)
				min=a[i];
		}
		System.out.println("Max: "+max);
		System.out.println("Min: "+min);
	}

	public static void demSoChanSoDuong(int[] a){
		int sochan=0, soduong=0;
		for(int i=0;i<a.length;i++){
			if(a[i]%2==0)
				sochan++;
			if(a[i]>0)
				soduong++;
		}
		System.out.println("So chan: "+sochan);
		System.out.println("So duong: "+soduong);
	}

	public static void timSoTrongDay(int[] a){
		Scanner sc = new Scanner(System.in);
		System.out.print("nhap x can tim: ");
		int x=sc.nextInt();
		for(int i=0;i<a.length;i++){
			if(a[i]==x){
				System.out.println("Tim thay tai vi tri: "+i);
				return;
			}
		}
		System.out.println("Khong tim thay trong day");
	}

	public static void sapXepTangDan(int[] a){
		for(int i=0;i<a.length-1;i++)
			for(int j=0;j<a.length-i-1;j++)
				if(a[j]>a[j+1]){
					int t = a[j];
					a[j]= a[j+1];
					a[j+1]= t;
				}
		inDaySo(a);
	}

	public static void main(){
		Scanner sc = new Scanner(System.in);
		int n;
		do {
			System.out.print("n: ");
			n=sc.nextInt();
			if(n<1 || n>100)
				System.out.println("nhap lai! (1<=n<=100)");
		}while (n<1 || n>100);
		int[] a = new int[n];
		System.out.print("nhap mang a[]: ");
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
		}

		while(true){
			System.out.println("""
			===== MENU =====
			1. In dãy số
			2. Tổng và trung bình cộng
			3. Số lớn nhất, nhỏ nhất
			4. Đếm số chẵn, số dương
			5. Tìm một số x trong dãy
			6. Sắp xếp tăng dần rồi in
			7. Thoát 
			""");
			System.out.print("Chọn: ");
			int option = sc.nextInt();
			switch (option) {
				case 1:
					inDaySo(a);
					break;
				case 2:
					tongVaTrungBinhCong(a);
					break;
				case 3:
					soMaxMin(a);
					break;
				case 4:
					demSoChanSoDuong(a);
					break;
				case 5:
					timSoTrongDay(a);
					break;
				case 6:
					sapXepTangDan(a);
					break;
				case 7:
					sc.close();
					return;
				default:
					System.out.println("Vui long chon tu 1 den 7.");
			}
		}
	}
}