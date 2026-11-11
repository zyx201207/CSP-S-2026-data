#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[514514];
int ans[514514];
unordered_map<int,int>mp[5555];
int nxt[214514];
unordered_set<int>s;
void f(int x){
	if(x==n+1)return ;
	s.insert(a[x]);
	f(nxt[x]);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]<a[i-1]){
			flaga=0;
			break;
		}
	}
	if(flaga){
		for(int i=1;i<=n;i++){
			ans[a[i]]=max(ans[a[i]],i);
		}
		for(int i=1;i<=m;i++){
			if(ans[i]==0){
				cout<<"0 ";
			}else{
				cout<<ans[i]<<' ';
			}
		}
		return 0;
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			mp[i-1].clear();
			for(int j=i;j<=n;j++){
				mp[j]=mp[j-1];
				if(mp[j][a[j]]!=0){//
					mp[j]=mp[mp[j][a[j]]];
				}
				mp[j][a[j]]=j;
			}
			for(auto it=mp[n].begin();it!=mp[n].end();it++){
				ans[it->first]++;
			}
			for(int j=1;j<=n;j++){
	//			for(auto it=mp[j].begin();it!=mp[j].end();it++)cout<<it->first<<' ';
	//			cout<<'\n';
				mp[j].clear();
			}
		}
		
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}else{
		for(int i=1;i<=n;i++){
			int x=i+1;
			while(x<=n&&a[x]!=a[i])x++;
			if(x==n+1){
				nxt[i]=i+1;
			}else{
				nxt[i]=x;
			}
			
		}
		for(int i=1;i<=n;i++){
			s.clear();
			f(i);
			for(auto it=s.begin();it!=s.end();it++){
				ans[*it]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	}
		
	return 0;
}
//rp++