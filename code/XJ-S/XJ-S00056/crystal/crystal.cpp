#include <bits/stdc++.h>
using ll=long long;
using namespace std;
constexpr int MAXN=500005;
ll arr[MAXN];
// inline void m_change(int m);
int main(){
    FILE* _f=freopen("crystal.in","r",stdin);
    _f=freopen("crystal.out","w",stdout);
    ll n,M;
    cin>>n>>M;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    --n;
    for(int i=0;i<n;i++) arr[i]=arr[i+1]-arr[i];
    int l=0,r=0,m=0,res=1;
    ll suml=0,dtl=0,sumr=arr[0],dtr=arr[0];
    for(;;){
        if(r<n-1&&dtl+dtr<=M){
            sumr+=arr[++r];
            dtr+=sumr;
            if(((r-l)&1)==0){
                sumr-=arr[m];
                dtr-=arr[m]*(r-m+1);
                suml+=arr[m];
                dtl+=arr[m]*(m-l+1);
                ++m;
            }
        }else if(l<r){
            if(l==m){
                ++l;
                sumr-=arr[m];
                dtr-=arr[m]*(r-m+1);
                ++m;
            }
            else{
                dtl-=suml;
                suml-=arr[l++];
                if(((r-l)>>1!=m)&&m>=l){
                    sumr-=arr[m];
                    dtr-=arr[m]*(r-m+1);
                    suml+=arr[m];
                    dtl+=arr[m]*(m-l+1);
                    ++m;
                }
            }
        }else if(l==r&&l<n-1){
            ++l,++r,++m;
            sumr=arr[l],dtr=arr[l];
        }else break;
        if(dtl+dtr<=M) res=max(res,r-l+2);
    }
    cout<<res<<'\n';
    return 0;
}