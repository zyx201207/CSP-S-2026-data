#include<bits/stdc++.h>
using namespace std;

int n,m;

vector<int> v;
int a[500010];
int _=1;

int vis[500010];
int c=0;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(!vis[x]) c++;
		vis[x]=1;
		
		v.push_back(x);
	}
	
	for(int i=1;i<=m;i++){
		cout<<i<<" ";
	}
	return 0;
}

