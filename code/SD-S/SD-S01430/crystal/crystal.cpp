#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+10;
int a[MAXN];
vector<int> ans;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll L=1;
	ll R=n;
	while(L<R){
		ll mid=(L+R)/2;
		ll sum=0;
		ll cnt=0;
		bool flag=false;
		for(int i=1;i<=mid;i++){
			sum+=(a[mid]-a[i]);
			cnt++;
			if(sum>m){
				flag=true;
				break;
			}
		}
		if(flag==false){
			ans.push_back(cnt);
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans[0]<<endl;
	return 0;
} 
/*5 8
-3 -1 2 2 7*/
/*5 5
1 2 4 8 9*/
