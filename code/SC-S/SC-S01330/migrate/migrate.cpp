#include<bits/stdc++.h>
using namespace std;

long long d,n;
map<int,int> mp;
const int INF = 2e6 + 7;
int B[INF];

void To(int start,int last,int bushu){
	if (start == last){
		mp[bushu]++;
		return ;
	}
	if (start > last) return ;
	int x = B[start] + d;
	for (int i = start + 1;i <= last;i++){
		if (B[i] <= x) To(i,last,bushu + 1);
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long ans = 0;
		cin>>n>>d;
		for (int i = 0;i < n;i++){
			cin>>B[i];
		}
		for (int i = 0;i < n;i++){
			for (int j = i + 2;j < n;j++){
				for (int i = 0;i <= n;i++) mp[i] = 0;
				To(i,j,0);
				for (int i = 0;i <= n;i++){
					if (mp[i] == 2){
						ans++;
						break;
					}
				} 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}