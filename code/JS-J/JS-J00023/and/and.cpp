#include<bits/stdc++.h>
using namespace std;
int fun(int x,int y){
    if(x==y)return x;
    int a[100]={0},b[100]={0},c[100];
    int c1=0;
    while(x>0){
        a[c1]=x%2;
        x/=2;
        c1++;
    }
    int c2=0,q=1,o=0;
    while(y>0){
        b[c2]=y%2;
        y/=2;
        c2++;
    }
    for(int i=0;i<=max(c1,c2);i++){
        if(a[i]==1&&b[i]==1)c[i]=1;
        else c[i]=0;
    }
    for(int i=0;i<=max(c1,c2);i++){
        o+=c[i]*q;
        q*=2;
    }
    return o;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,max=0,hp;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(m==1){
            cout<<a[n-1];
            return 0;
    }
    if(m==2){
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                hp=fun(a[i],a[j]);
                if(hp>max){
                    max=hp;
                }
            }
        }
    }
    if(m==n){
        hp=fun(a[0],a[1]);
        for(int i=2;i<n;i++){
            hp=fun(hp,a[i]);
        }
        cout<<hp;
        return 0;
    }
    cout<<max;
    return 0;
}
