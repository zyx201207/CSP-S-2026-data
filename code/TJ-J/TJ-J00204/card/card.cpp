#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int a[M];
int cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool isa=1;
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]<a[i-1]){
			isa=0;
		}
	}
	if(isa){
		int now=a[1];
		for(int i=1;i<=n;i++){
			cnt[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<' ';
		}
		cout<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		map<int,int> mp;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				while(s.top()!=a[j]){
					mp[s.top()]=0;
					s.pop();
				}
			}
			else{
				s.push(a[j]);
				mp[a[j]]=1;
			}
		}
		while(s.size()){
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	cout<<'\n';
	
	return 0;
}
