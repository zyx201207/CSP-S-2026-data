#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pi pair<int,int>
int n,m;
const int N=5e5+5;
int a[N];
int need[N];
int num[N];
int all[N];
int more[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<=5000){
        int ans=0;
        for(int i=2;i<=n;i++){
            int t=m,l=i-1;

            while(t>0&&l>0){
                if(a[i]-a[l]<=t){
                    t-=a[i]-a[l];
                    l--;
                }
                else{
                    break;
                }
            }
            ans=max(i-l,ans);
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<n;i++){
        need[i]=a[i+1]-a[i];
    }
    for(int i=1;i<=n;i++){
        num[i]=num[i-1]+need[i];
        //cout<<num[i]<<' ';
    }
    //cout<<endl;
    for(int i=1;i<=n;i++){
        all[i]=all[i-1]+need[i-1]*(i-1);
    }
    for(int i=1;i<=n;i++){
        more[i]=more[i-1]+num[i];
        //cout<<more[i]<<' ';
    }
    //cout<<endl;
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=0,r=i-1;
        while(l<r){
            int mid=(l+r)>>1;
            int req=all[i-1]-(i-mid-1)*num[i-1]+ more[i-2-mid] ;
            if(req>m){
                r=mid-1;
            }
            else{
                l=mid+1;
                ans=max(ans,mid+1);
            }
        }
    }
    cout<<ans;
    return 0;
}
