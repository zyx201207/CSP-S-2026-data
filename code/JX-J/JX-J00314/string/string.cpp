#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct Node{
    ll cnt;
    char ch;
};
Node a[N];
int r;
int n;
ll Cnt(ll x,char c){
    ll k=0,sum=0,_cnt=0;
    while(sum<x){
        _cnt=min(x-sum,a[r].cnt);
        if(a[r].ch!=c){
            k+=_cnt;
        }
        sum+=a[r].cnt;
        if(sum<=x)r--;
        else{
            a[r].cnt-=_cnt;
        }
    }
    return k;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].cnt>>a[i].ch;
        sum+=a[i].cnt;
    }
    sum/=2;
    ll res=0,ans=0;
    //cout<<sum<<"\n";
    r=n;
    for(int i=1;i<=n;i++){
        ll x=min(sum-res,a[i].cnt);
        ans+=Cnt(x,a[i].ch);
        res+=a[i].cnt;
        //cout<<n<<" "<<ans<<" "<<res<<" "<<sum<<"\n";
        if(res>=sum){
			//cout<<1<<"\n";
			//cout<<ans<<" "<<res<<" "<<sum<<"\n";
			break;
		}
    }
    cout<<ans;
    return 0;
}
