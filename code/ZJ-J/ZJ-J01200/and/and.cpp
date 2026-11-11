#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
const int M = 2^30-1;
struct node{ int arr,num; }cnt[N];
bool cmp(node x,node y){
	return (x.arr<y.arr,x.num<y.num);
}
void solve(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>cnt[i].arr,cnt[i].num=__builtin_popcount(cnt[i].arr);
    sort(cnt,cnt+n,cmp); int ans=cnt[n-1].arr;
    for(int i=0;i<n;i++) cout<<cnt[i].arr<<" "<<cnt[i].num<<"\n";
    for(int i=m-1;i>m-n-1;i--)
        ans&=cnt[i].arr;
    cout<<ans;
}             
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int T=1; /*cin>>T;*/
    while(T--) solve();
    return 0;
}