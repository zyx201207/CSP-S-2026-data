#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,ll;
long long a[500050],b[500050];
int main(){
    freopen("crystal.in","r,stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=a[0],r=a[n];
    long long mid=a[0],po=1;
    while(l<r){
        mid=(l+r)/2;
        int st,nm=m;
        for(int i=1;i<=n;i++){
            b[i]=mid-a[i];
        }
        for(int i=1;i<=n;i++){
            if(l>=0){
                st=i;
                break;
            }
        }
        for(int i=st;i>=1;i++){
            if(nm>=b[i]){
                nm+=b[i];
            }
        }
        if(nm>0&&nm<po){
            r=mid-1;
        }else{
            l=mid;
        }
    }
    int ww;
    for(int i=1;i<=n;i++){
        if(a[i]<=mid){
            ++cnt;
        }else{
            if(a[i]==ww){
                ++cnt;
            }else{
                ww=a[i];
            }
        }
    }
    cout<<cnt;
    return 0;
}
