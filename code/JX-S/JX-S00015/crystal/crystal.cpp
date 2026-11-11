#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],b[N],maxn,cnt,sum,last,c[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
        c[i]=c[i-1]+b[i];
    }
    for(int i=1;i<n;i++){
        cnt++;
        sum+=cnt*b[i];
        while(sum>m){
            sum=sum-c[i]+c[last++];
            cnt--;
        }
        maxn=max(maxn,cnt+1);
    }
    cout<<maxn;
    return 0;
}
