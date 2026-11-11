#include<bits/stdc++.h>
#define int long long
using namespace std;
queue <int> q;
int a[200005];
signed main(){
	freopen("card.in ","r",stdin);
	freopen("card.out ","w",stdout);/////////
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,an=1;
	cin>>n>>m;
	int ans=1,h=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
		for(int i=0;i<q.size()-1;i++){
			if(a[i]==a[i]||h==1) q.pop(),h=1;
		}
	}
	for(int i=0;i<q.size();i++){
		if(q.front()==an) cout<<1<<" ";
		if(!q.empty()) q.pop();
	}
	int p=1;
	while(p++){
		for(int i=p;i<n-p+1;i++){
			q.push(a[i]);
			for(int i=0;i<q.size()-1;i++){
				if(a[i]==a[i]||h==1) q.pop(),h=1;
			}
		}
		for(int i=0;i<q.size();i++){
			if(q.front()==an) cout<<1<<" ";
			if(!q.empty()) q.pop();
		}
	}
	return 0;
}
