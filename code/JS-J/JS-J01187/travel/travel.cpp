#include<bits/stdc++.h>
using namespace std;
char a[15];
int b,c,d,e;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=10;i++)cin>>a[i];
    if(a[1]==a[6]&&a[2]==a[7])b=1;
    if(b&&a[3]==a[8]&&a[4]==a[9])c=1;
    if(c&&(a[5]>='D'&&a[10]>='D'||a[5]<='C'&&a[10]<='C'))d=1;
    if(d&&(abs(a[5]-a[10])==1||a[5]=='D'&&a[10]=='F'||a[5]=='F'&&a[10]=='E'))e=1;
    cout<<b<<c<<d<<e;
    return 0;
}
