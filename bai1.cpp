#include<iostream>
#include<algorithm>
using namespace std;
struct PS{
    int ts,ms;
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
void xuat(PS &x){
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
int main(){
    //Nhập phân số
    PS x; nhap(x);
    cout<<"Phan so ";xuat(x);cout<<" sau khi rut gon la: ";
    rut_gon(x);
    xuat(x);
    return 0;
}
