#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
int n,m,a[N],aa[N]={},cnt[N]={};
int A=1,B=1;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            A=0;
        }
    }
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
            B=0;
        }
    }
    int k=0,kk=1;
    for(int i=1;i<=n;i++){
        aa[k+i]=kk+1;
        k+=i;
        kk++;
    }
    for(int i=1;i<=n;i++){
        if(aa[i]!=0) continue;
        aa[i]=aa[i-1];
    }
    if(A){
        //cout<<"A";
        if(n>=m){
            cout<<aa[m];
        }else{
            cout<<aa[n];
        }
        return 0;
    }else if(B){
        //cout<<"B";
        int cha=a[2]-a[1];
        int code=m/cha;
        if(n>=code){
            cout<<aa[code];
        }else{
            cout<<aa[n];
        }
        return 0;
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1,lwx=0,lwxx=1;
        for(int i=l;i<r;i++){
            lwx+=a[r]-a[i];
            lwxx=r-l+1;
        }
        if(lwx<=m){
            for(int i=1;i<=n;i++){
                if(a[i]==a[i+1]&&a[i]==a[r+1]){
                    lwxx++;
                }
            }
            if(lwxx+1>n){
                cout<<n;
                break;
            }else{
                cout<<lwxx+1;
                break;
            }
        }else if(a[mid]-a[mid-1]>=a[mid+1]-a[mid]&&a[mid+1]!=a[mid]){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }

    return 0;
}
