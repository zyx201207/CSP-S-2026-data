#include<bits/stdc++.h>
using namespace std;
string cc1,cc2,ss1,ss2;
int a[5]={0};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cc1;
    cin>>ss1;
    cin>>cc2;
    cin>>ss2;
    if(cc1==cc2){
        a[1]=1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]){
        a[2]=1;
    }else{
        cout<<"1000";
        return 0;
    }
    if((ss1[2]<'D'&&ss2[2]<'D')||(ss1[2]>'C'&&ss2[2]>'C')){
        a[3]=1;
    }
    else{
        cout<<"1100";
        return 0;
    }
    if((ss1[2]==(ss2[2])+1)||(ss2[2]==(ss1[2])+1)){
        a[4]=1;
    }
    else{
        cout<<"1110";
        return 0;
    }
    for(int i=1;i<=4;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
