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
    if(x.ts>0&&x.ms<0){
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
    cout<<x.ts<<'/'<<x.ms;
}
// Hàm tính a+b và a-b
void cong_tru(PS a,PS b){
    //Quy đồng 2 phân số a và b sao cho cùng mẫu
    rut_gon(a); rut_gon(b);
    long long lcm=a.ms/__gcd(a.ms,b.ms)*b.ms;
    PS c={a.ts*lcm/a.ms+b.ts*lcm/b.ms,lcm};
    PS d={a.ts*lcm/a.ms-b.ts*lcm/b.ms,lcm};
    rut_gon(c);
    rut_gon(d);
    // In ra kết quả
    xuat(a); cout<<" + "; xuat(b); cout<<" = "; xuat(c); cout<<'\n';
    xuat(a); cout<<" - "; xuat(b); cout<<" = "; xuat(d); cout<<'\n';
}
// Hàm tính a*b, a/b
void nhan_chia(PS a,PS b){
    rut_gon(a); rut_gon(b);
    PS c={a.ts*b.ts,a.ms*b.ms};
    rut_gon(c);
    xuat(a); cout<<" * "; xuat(b); cout<<" = "; xuat(c); cout<<'\n';
    if(b.ts==0){
        cout<<"Khong the chia duoc cho 0";
        return;
    }
    PS d={a.ts*b.ms,a.ms*b.ts};
    rut_gon(d);
    xuat(a); cout<<" / "; xuat(b); cout<<" = "; xuat(d); cout<<'\n';
}
int main(){
   //Nhập hai phân số
   PS a,b; nhap(a); nhap(b);
   //Tính toán các kết quả cộng, trừ, nhân, chia của 2 số thập phân
   cong_tru(a,b);
   nhan_chia(a,b);
   return 0;
}
