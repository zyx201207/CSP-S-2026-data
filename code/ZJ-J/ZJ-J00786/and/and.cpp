#include <bits/stdc++.h>
using namespace std;
typedef long long inte;
bool idbit(inte id, inte n){
	return (n>>id)&1;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	inte n, m;
	cin>>n>>m;
	vector<inte> a(n+1);
	vector<short> flag(n+1, true);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=30;
	int ans=0;
	while((i--)>=0){
		int cnt=0;
		vector<short> fl(n+1, true);
		for(int j=1;j<=n;j++){
			if(!flag[j])continue;
			bool b=idbit(i, a[j]);
			if(b) cnt+=1;
			else fl[j]=false;
		}
		if(cnt>=m){
			ans |= 1<<i;
			for(int i=1;i<=n;i++){
				flag[i] &= fl[i];
			}
		}
	}
	cout<<ans;
	return 0;
} 
