#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int a[N],l[N],t[N],vis[N];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			v.push_back(a[j]);
			if(!vis[a[i]]){
				l[a[i]]=i;
				vis[a[i]]=1;
			}else{
				int cnt=l[a[i]]-1;
				for(int k=l[a[i]]-1;k<i;k++){
					v.erase(v.begin()+cnt);
				}
				l[a[i]]=i;
			}
		}
		memset(vis,0,sizeof(vis));
		for(int j=0;j<v.size();j++){
			t[v[j]]++;
		}
		memset(vis,0,sizeof(vis));
		memset(l,0,sizeof(l));
		v.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
