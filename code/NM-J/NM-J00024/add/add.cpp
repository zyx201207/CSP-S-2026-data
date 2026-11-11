#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	freopen("add.in", "r", stdin);
	freopen("add.out", "w", stdout);
	LL n, m;
	cin>>n>>m;
	vector<LL> now(n, 0);
	for(int i=0; i<n; i++)cin>>now[i];
	LL ans=0;
	for(int i=30; i>=0; i--){
		LL nowcnt=0;
		for(int j=0; j<now.size(); j++){
			if((now[j]>>(i-1))%2)nowcnt++;
		}
		if(nowcnt>=m){
			ans+=1<<i;
			vector<LL> nnow;
			for(int j=0; j<now.size(); j++){
				if((now[j]>>(i-1))%2){
					nnow.push_back(now[j]);
				}
			}
			now.clear();
			for(int j=0; j<nnow.size(); j++)now.push_back(nnow[j]);
		}
		for(int j=0; j<now.size(); j++)cout<<now[j]<<' ';
		cout<<endl;
	}
	cout<<ans;
	return 0;
}
