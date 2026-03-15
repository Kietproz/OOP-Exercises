#include<iostream>
using namespace std;
//Khởi tạo số ngày tối đa trong một tháng
int numDay[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//Hàm nhập ngày
struct Date{
    int ngay,thang,nam;
};
void nhap(Date &a){
    cin>>a.ngay>>a.thang>>a.nam;
}
//Hàm xử lý để cho ra kết quả của ngày tiếp theo
void process(Date &a){
    a.ngay++;
    //Kiểm tra xem số ngày có vượt quá số ngày tối đa trong tháng không
    if(a.ngay>numDay[a.thang]){
        //Kiểm tra xem số tháng có vượt quá số tháng tối đa trong năm không
        a.thang++;
        if(a.thang>12){
            a.ngay=1;
            a.thang=1;
            a.nam++;
        }
        else{
            a.ngay=1;
        }
    }
}
void in(Date a){
    if(a.ngay<10){
        cout<<0;
    }
    cout<<a.ngay<<'/';
    if(a.thang<10){
        cout<<0;
    }
    cout<<a.thang<<'/';
    if(a.nam<10){
        cout<<0;
    }
    cout<<a.nam;
}
int main(){
    //Nhập ngày
    Date a;nhap(a);
    //Xác định xem có phải là năm nhuận không để xác định số ngày của tháng 2
    if(a.nam%400==0||(a.nam%100!=0&&a.nam%4==0)){
        numDay[2]=29;
    }
    //Tìm ngày tiếp theo
    process(a);
    //In ra ngày tiếp theo
    in(a);
    return 0;
}