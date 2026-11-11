#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","r",stdout);
    char a[2],c[2];
    char b[3],d[3];
    int p,q,m,n,x,y;
    cin>>a>>b>>c>>d;
    p=a[0]+a[1];
    q=c[0]+c[1];
    x=b[0]+b[1];
    y=d[0]+d[1];
    if(p==q) {
            if(y-x==48){
           m=b[2];
           n=d[2];
           if((m==65||m==66||m==67)&&(n==65||n==66||n==67)||(m==68||m==69)&&(n==68&&n==69)){
           if((m-n==1||n-m==1)&&((m!=67&&n!=68)&&(m!=68&&n!=67))) cout<<"1111";
           else cout<<"1110";
           }
           else cout<<"1100";
            }
            else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}
