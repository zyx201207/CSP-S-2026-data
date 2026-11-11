#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005]={0};
int sum=-1;
int t(int a){
    int b=0;
    while(a){
        b*=10;
        b+=a%2;
        a/=2;
    }
    return b;
}
void ss(int w,int c,int r){
    if(w==m){
        sum=max(sum,c);
        return ;
    }
    for(int i=1;i<=n;i++){
        c+=(a[i]&r);
        ss(w++,c,a[i]);
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=t(a[i]);
    }
    for(int i=1;i<=n;i++){
        ss(1,0,a[i]);
    }
    cout<<sum;
    return 0;
}
