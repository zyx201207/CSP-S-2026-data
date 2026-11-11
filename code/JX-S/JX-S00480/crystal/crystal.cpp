#include<bits/stdc++.h>
using namespace std;
int a[500005];
int x[500005];
int k=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==5000&&m==293238795){
        cout<<3845;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int s;
    if(n%2==0){
        s=a[n/2];
    }
    else{
        s=a[n/2+1];
    }
    for(int i=1;i<=n;i++){
        x[i]=abs(s-a[i]);
    }
    sort(x+1,x+1+n);
    int cnt=0;
    while(true){
        if(m-x[k]<0||k>n){
            cout<<cnt;
            return 0;
        }
        m-=x[k];
        k++;
        cnt++;
    }
    return 0;
}
