#include<iostream>
using namespace std;

int crystals,points;
int bin[50000];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>crystals>>points;
    if(points>2147483647){
        cout<<"gugu~";
    }
    for(int i=0;i<crystals;i++){
        int temp;
        cin>>temp;
        bin[temp]++;
    }
    int mode=-1,modenum=-1;
    for(int i=0;i<50000;i++){
        if(bin[i]>=mode){
            mode=bin[i];
            modenum=i;
        }
    }
    int result=mode;
    for(int i=modenum;i>0;i++){
        points-=(modenum-i)*bin[i];
        result+=bin[i];
        if(points-bin[i-1]<=0)break;
    }
    cout<<result;
    return 0;    
}
