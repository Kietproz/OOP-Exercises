#include<iostream>
#include<algorithm>
using namespace std;
struct PS{
   long long ts,ms;
};
//Hàm nhập phân số
void nhap(PS &x){
    //Lần lượt nhập tử số và mẫu số
    cin>>x.ts>>x.ms;
}
//Hàm rút gọn phân số
void rut_gon(PS &x){
    //Tìm ước chung lớn nhất của tử và mẫu rồi chia cả tử và mẫu với ước chung vừa tìm được
    long long gcd=__gcd(x.ts,x.ms);
    x.ts/=gcd; x.ms/=gcd;
    //Điều chỉnh lại định dạng phân số phù hợp
    if(x.ms<0){
        x.ts=-x.ts;
        x.ms=-x.ms;
    }
}
//Hàm xuất 
void xuat(PS x){
    if(x.ts==0){
        cout<<0;
        return;
    }
    if(x.ms==1){
        cout<<x.ts;
        return;
    }
    cout<<x.ts<<'/'<<x.ms<<'\n';
}
//Hàm so sánh 2 phân số
void so_sanh(PS a,PS b){
   //Rút gọn 2 phân số a và b
   rut_gon(a); rut_gon(b);
   //Quy đồng 2 phân số rồi so sánh
   int x=a.ts*b.ms,y=b.ts*a.ms;
   if(x>=y){
      xuat(a);
   }
   else{
      xuat(b);
   }
}
int main(){
   //Nhập hai phân số
   PS a,b; nhap(a); nhap(b);
   //Thực hiện so sánh hai số
   so_sanh(a,b);
   return 0;
}
