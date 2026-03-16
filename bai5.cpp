#include<iostream>
using namespace std;
struct HocSinh{
    string name;
    double diem_toan,diem_van;
};
// Hàm nhập thông tin học sinh
void nhap(HocSinh &a){
    getline(cin,a.name);
    //Nhập riêng diem_toan, diem_van vì struct không cho nhập trực tiếp kiểu double
    double b,c; cin>>b>>c;
    a.diem_toan=b; a.diem_van=c;

}
// Hàm tính điểm trung bình
void dtb(HocSinh a){
    double c=(a.diem_toan+a.diem_van)/2;
    cout<<"Diem trung binh hoc sinh "<<a.name<<" la: "<<c;
}
int main(){
    //Nhập thông tin học sinh
    HocSinh a; nhap(a);
    //Tính điểm trung bình học sinh
    dtb(a);
    return 0;
}
