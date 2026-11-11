#include<bits/stdc++.h>
using namespace std;
int a[500003],p[300005],s[300005],t[300005];
vector<int> b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]=i;
		s[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(p[i]==n)continue;
		b[i].push_back(a[p[i]+1]);
		t[a[p[i]+1]]++;
	}
//	for(int i=1;i<=m;i++){
//		cout<<t[i]<<' ';
//	}
//	cout<<endl;
	queue<int> q;
	for(int i=1;i<=m;i++){
		if(t[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int k=q.front();
		q.pop();
//		cout<<k<<' ';
		for(int i=0;i<b[k].size();i++){
			s[b[k][i]]+=s[k];
			t[b[k][i]]--;
			if(t[b[k][i]]==0)q.push(b[k][i]);
		}
	}
//	cout<<endl;
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
} 
