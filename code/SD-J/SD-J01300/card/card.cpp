#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
int a[500010];
int ans[300010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool sp=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!(a[i-1]<=a[i])){
			sp=0;
		}
	}
	if(sp){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(i!=1&&a[i]!=a[i-1]){
				cout<<cnt<<" ";
			}
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	for(int j=1;j<=n;j++){
		vector<int> last;
		vector<int> r;
		vector<int> s,e;
		last.resize(m+1,0);
		r.resize(n+1,0);
		e.resize(n+1,0);
		s.resize(n+1,0);
		int cnt=0;
		for(int p=j;p<=n;p++){
			if(last[a[p]]){
				r[last[a[p]]]=p;
				e[p]++;
				s[last[a[p]]]++;
			}
			last[a[p]]=p;
		}
		for(int p=j;p<=n;p++){
			if(e[p]){
				cnt=0;
			}
			if(s[p]){
				if(!cnt){
					cnt=1;
				}
				else{
					e[r[p]]--;
				}
			}
			if(!cnt){
				ans[a[p]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m) cout<<' ';
	}
	return 0;
}
