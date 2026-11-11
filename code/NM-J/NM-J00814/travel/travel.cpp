#include<bit/stdc++.h>
using namespace std;
int car1[1],car2[1],sit1[1],sit2[1];
char r[1],x[1];
int main(){
freopen("travel.in","r",in);
freopen("travel.out","w",out);
for(int i=1;i<=1;i++)cin>>car1[i];
for(int j=1;j<=1;j++)cin>>sit1[j];
for(int k=1;k<=1;k++)cin>>r[k];
for(int l=1;l<=1;l++)cin>>car2[l];
for(int z=1;z<=1;z++)cin>>sit2[z];
for(int b=1;b<=1;b++)cin>>x[b];
if(car1[1]==car2[1]){cout<<'1';else cout<<'0';}
if(sit1[1]==sit2[1]){cout<<'1';else cout<<'0';}
if((r[1]-x[1]=='1'||x[1]-r[1]=='1')&&(r[1]!='C'&&x[1]!='D'||x[1]!='C'&&r[1]!='D')){cout<<'1';else cout<<'0';}
if(r[1]-x[1]=='1'||x[1]-r[1]=='1'){cout<<'1';else cout<<'0';}
return 0;
}
