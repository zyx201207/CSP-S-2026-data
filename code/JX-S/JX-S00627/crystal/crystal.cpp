
#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+10;
int n,m;
int a[N];
int sum1[N],sum2[N];
int b[N],c[N],cnt1,cnt2;
int ans;
bool check(int i,int x,int t){
    int s=(i-x+1)*b[i]-(sum1[i]-sum1[x-1]);
    if(s<=t)return true;
    else return false;
}
bool check2(int i,int x,int t){
    int s=(i-x+1)*c[i]-(sum2[i]-sum2[x-1]);
    if(s<=t)return true;
    else return false;
}
bool check3(int i,int x,int t){
    int s=(cnt1-x+1)*c[i]-(sum1[cnt1]-sum1[x-1]);
    if(s<=t)return true;
    else return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]<=0)b[++cnt1]=a[i];
        else if(a[i]>0)c[++cnt2]=a[i];
    }
    for(int i=1;i<=cnt1;i++){
        sum1[i]=sum1[i-1]+b[i];
    }
    for(int i=1;i<=cnt2;i++){
        sum2[i]=sum2[i-1]+c[i];
    }
    for(int i=1;i<=cnt1;i++){
        if(m>=i*b[i]-sum1[i]){
            ans=max(ans,i);
            continue;
        }
        int l=1,r=i+1;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(i,mid,m))r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    for(int i=1;i<=cnt2;i++){
        if(m<i*c[i]-sum2[i]){
            int l=1,r=i+1;
            while(l<r){
                int mid=(l+r)>>1;
                if(check2(i,mid,m))r=mid;
                else l=mid+1;
            }
            ans=max(ans,i-l+1);
            continue;
        }
        else{
            int k=m-(i*c[i]-sum2[i]);
            if(k>=c[i]*cnt1-sum1[cnt1]){
                ans=max(ans,i+cnt1);
                continue;
            }
            int l=1,r=cnt1+1;
            while(l<r){
                int mid=(l+r)>>1;
                if(check3(i,mid,k))r=mid;
                else l=mid+1;
            }
            ans=max(ans,i+cnt1-l+1);
        }
    }
    cout<<ans;
    return 0;
}