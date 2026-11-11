#include <bits/stdc++.h>
using namespace std;
const int N=5e5+114;
int n;
long long m;
long long a[N],sum[N];
int ans;

bool check(int st,int ed){
    long long ned=a[ed]*(ed-st);
    long long now=sum[ed-1]-sum[st-1];
    if(now+m>=ned)
        return 1;
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        int l=1,r=i,mid;
        int res=1;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid,i)==1){
                r=mid-1;
                res=max(res,i-mid+1);
            }else
                l=mid+1;
        }
        ans=max(ans,res);
    }
    cout<<ans<<"\n";
    return 0;
}
//5 5 1 2 4 8 9

//    freopen("crystal.in","r",stdin);
//    freopen("crystal.out","w",stdout);

/*
会赢吗？
会赢的，我的同学们都还在看着呢，
让我再耍会儿帅吧
*/
