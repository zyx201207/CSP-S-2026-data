#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m,ans;
vector<int>V,tmp;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1,x;i<=n;i++)cin>>x,V.push_back(x);
    for(int i=30;i>=0;i--){
    	int cnt=0;
    	for(int x:V)if((x>>i)&1)cnt++;
    	if(cnt>=m){
    		ans+=(1<<i);
    		tmp.clear();
    		for(int x:V)if((x>>i)&1)tmp.push_back(x);
    		V=tmp;
		}
	}
	cout<<ans<<'\n';
    return 0;
}