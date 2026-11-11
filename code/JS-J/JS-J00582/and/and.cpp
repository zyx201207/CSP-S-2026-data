#include<bits/stdc++.h>
using namespace std;
int f(int n){
    int a=1;
    while(n!=0){
        a=a*10+n%2;
        n=n/2;
    }
    int x=0;
    while(a!=0){
        x=x*10+a%10;
        a=a/10;
    }
    x=(x-1)/10;
    return x;
}
int dx(int a,int b){
    int x=f(a);
    int y=f(b);
    int ans=1;
    while(x!=0){
        int a1=x%10;
        int b1=y%10;
        if((a1==1&&b1==1))ans=ans*10+1;
        if(a1==0||b1==0)ans=ans*10;
    }
    int x1;
    while(ans!=0){
        x1=x1*10+ans%10;
        ans=ans/10;
    }
    x1=(x1-1)/10;
    return x1;
}
int zh(int a,int b){
    int l=dx(a,b);
    int i=-1;
    int ans=0;
    while(l!=0){
        i++;
        ans+=pow(l%10,i);
        l=l/10;
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int maxx=INT_MIN;
    int n,m,a[1000005];
    cin>>n,m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1)cout<<maxx;
return 0;
}
