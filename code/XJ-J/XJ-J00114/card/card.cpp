#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans[N];
bool cnt[N];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		while(!s.empty()) s.pop();
		for(int j=i;j<=n;j++){
			while(!s.empty()&&cnt[a[j]]){
				cnt[a[s.top()]]=0;
				s.pop();
			}
			s.push(j);
			cnt[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(cnt[j]) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
