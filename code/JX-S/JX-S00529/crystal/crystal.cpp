#include<bits/stdc++.h>
using namespace std;
long long n,m,c,e;
int a[500005],b[500005];
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0){
            if(a[i]>a[i-1]){t

                b[i]=a[i]-a[i-1];
            }
            else{
                b[i]=a[i-1]-a[i];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            int d=0;
            d=b[i]+b[i-1];
            if(d>=m){
                e=1;
                break;
            }
        }
        c=c+1;
    }
        cout<<c<<" ";
    return 0;
}

