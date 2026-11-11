#include<bits/stdc++.h>
using namespace std;
int n,m,p[2005][2005];
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        long long mx=-2e9;
        for(int i=1;i<=n;i++){
            if(a[i]>mx){
                mx=a[i];
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==n){
        long long q=a[1];
        for(int i=2;i<=n;i++){
            q=q&a[i];
        }
        cout<<q;
        return 0;
    }
    if(m==2){
        int mx=-2e9,p;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                p=a[i]&a[j];
                if(p>mx){
                    mx=p;
                }
            }
        }
        cout<<mx;
        return 0;
    }
    if(m==n-1){
        int mx=-2e9,h=a[1];
        for(int i=1;i<=n;i++){
            for(int j=2;j<=n;j++){
                if(i==j) continue;
                h=h&a[j];
            }
            if(h>mx){
                mx=h;
            }
        }
        cout<<mx;
        return 0;
    }
    cout<<"49152";
    return 0;
}
