#include<bits/stdc++.h>
using namespace std;
struct WZ{
    int ch;
    int p;
    char wz;
}a[2];
int ans[4]={0,0,0,0};
int main(){
    frepoen("travel.in","r","stdin");
    frepoen("travel.out","W","stdout");
    for(int i=1;i<=2;i++){
        cin>>a[i].ch>>a[i].p>>a[i].wz;
    }
    for(int i=1;i<=2;i++){
        if(a[i].ch==a[i+1].ch)
            ans[1]=1;
        else
            break;
        if(a[i].p==a[i+1].p){
            ans[2]=1;
            if(((int)a[i].wz-67)<=0 && ((int)a[i+1].wz-67)<=0){
                ans[3]=1;
            }
            else if(((int)a[i].wz+2)>=70 && ((int)a[i].wz+2)>=70){
                ans[3]=1;
            }
        }
        if(a[i].wz!='C' && a[i].wz!='D' && a[i+1].wz!='C' && a[i+1].wz!='D'){
            if((char)(a[i].wz+1)==a[i+1].wz){
                ans[4]=1;
            }

        }
        else if((a[i].wz=='D'&&a[i+1].wz=='F')||(a[i].wz=='F'&&a[i+1].wz=='D')){
            ans[4]=1;
        }
    }

    for(int i=1;i<=4;i++){
        cout<<ans[i];
    }
    return 0;
}
