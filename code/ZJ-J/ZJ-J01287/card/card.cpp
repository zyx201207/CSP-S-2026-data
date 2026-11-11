#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
int n,m;
ll a[N],t[N],ans[N];
void solve(int o){
	memset(t,0,sizeof(t));
	vector<int> v;
	for(int i=o;i<=n;i++){
		v.push_back(a[i]);
		t[a[i]]++;
		if(t[a[i]]>1){
			for(int j=1;j<=i;j++){
				if(a[j]==a[i]){
					for(int k=n;k>=j;k--){
						v.pop_back();
					}
					v.push_back(a[i]);
					t[a[i]]--;
					break;
				}
			}
		}
	}
	for(auto e:v){
		ans[e]++;
	}
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
