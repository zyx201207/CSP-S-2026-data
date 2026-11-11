#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+1e2;
int n,m;
int a[N],ans[N],fans[N],pans[N];;
int p[N];
vector<int> s[N];
int f[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//	cout<<sizeof(r)/1024/1024;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]].push_back(i);
		p[i]=s[a[i]].size();
	}
	for(int i=1;i<=n;i++){
		if(p[i]!=s[a[i]].size()) ++ans[a[i]];
		else{
			int q=i;
			while(p[q]==s[a[q]].size()&&q!=n){
				fans[a[q]]++;
				q++;
			}
			++ans[a[q]];
		}
	}
	for(int i=1;i<=m;i++){
		int loc=s[i][s[i].size()-1];
		memset(pans,0,sizeof(pans));
		for(int j=loc;j<=n;++j){
			if(s[a[j]].size()>p[j]) pans[a[j]]=1,j=s[a[j]][p[j]]-1;
			else pans[a[j]]=1;
		}
		for(int j=1;j<=m;j++) fans[j]+=ans[i]*pans[j];
	}
	for(int i=1;i<=m;i++) cout<<fans[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/