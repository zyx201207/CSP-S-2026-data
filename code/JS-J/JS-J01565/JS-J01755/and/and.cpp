#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,a1,a2,a3;
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=4)f=0;
        if(a[i]==1)a1++;
        if(a[i]==2)a2++;
        if(a[i]==3)a3++;
    }
    if(m==1){
        int mx=0;
        for(int i=1;i<=n;i++)mx=max(mx,a[i]);
        cout<<mx;
        return 0;
    }
    else if(m==2){
        int mx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,(a[i]&a[j]));
            }
        }
        cout<<mx;
        return 0;
    }
    else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++)ans=(ans&a[i]);
        cout<<ans;
        return 0;
    }
    else if(f){
        if(a3>=m){
            cout<<3;
            return 0;
        }
        else if(a3+a2>=m){
            cout<<2;
            return 0;
        }
        else if(a3+a2+a1>=m){
            if(a3+a1>=m){
                cout<<1;
                return 0;
            }
            else if(a1>=m){
                cout<<1;
                return 0;
            }
            if(a2+a1>=m){
                cout<<0;
                return 0;
            }
        }
    }
    return 0;
}
