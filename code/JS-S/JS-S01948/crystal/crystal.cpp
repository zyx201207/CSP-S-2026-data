#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],maxx=0,minn=1e12+5;
int check(int x){
    int p=lower_bound(a+1,a+n+1,x)-(a+1),q=upper_bound(a+1,a+n+1,x)-(a+1);
    int sum=q-p,num=m;
    //cout<<"\n"<<x<<" "<<p<<" "<<sum<<"\n";
    while(p>0){
        //cout<<p<<" "<<num<<" "<<a[p]<<"\n";
        if(x-a[p]<=num){
            num-=(x-a[p]);
            ++sum;
            --p;
        }else{
            break;
        }
    }
    return sum;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        minn=min(minn,a[i]);
    }
    sort(a+1,a+n+1);
    int ans=0;
    if(n<=5000){
        for(int i=1;i<=n;i++)
            ans=max(ans,check(a[i]));
    }else if(maxx-minn<=100){
        for(int i=minn;i<=maxx;i++)
            ans=max(ans,check(i));
    }else{
        ans=(1.0+sqrt(1+(m*8.0)/(a[2]*1.0-a[1]*1.0)))/2;
    }
    cout<<ans<<"\n";
    return 0;
}
/*
5 8
-3 -1 2 2 7
*/
