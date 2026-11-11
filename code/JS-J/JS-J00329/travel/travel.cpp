#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==b){
        cout<<'1';
    }
    else{
        cout<<'0';
    }
    string x[5][18]={0};
    string y[18]={'01','02','03','04','05','06','07','08','09','10','11','12','13','14','15','16','17','18'}
    for(int i=0;i<5;i++){
        for(int j=0;j<18;j++){
            if(i==0){
                x[i][j]=y[j]+'F';
            }
            else if(i==1){
                x[i][j]=y[j]+'D';
            }
            else if(i==2){
                x[i][j]=y[j]+'C';
            }
            else if(i==3){
                x[i][j]=y[j]+'B';
            }
            else{
                x[i][j]=y[j]+'A';
            }
        }
    }
    for(int i=0;i<5;i++){

    }
}




