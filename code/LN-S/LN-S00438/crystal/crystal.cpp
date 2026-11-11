#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[5001],b[5000],x=0,y=0,z=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n>5000){
        m/=a[2]-a[1];
        int t=0;
        while(m>=t+1){
            t++;
            m-=t;
        }
        cout<<t;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(i==1) continue;
        x=a[i]-a[i-1];
        y++;
        z+=x*y;
        if(m>=z) continue;
        else {
            cout<<y;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
