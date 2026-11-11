#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005];
bool vis[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		b[i]=0;
	}
	int h=1;
	int k;
	for(int w=1;w<n;w++){
		vector<int> v;
		for(int i=w;i<=n;i++){
			if(vis[a[i]]==false){
				v.push_back(a[i]);
				vis[a[i]]==true;
				k=i;
			}else{
				for(int j=k;j<i;j++){
					v.pop_back();
				}
				k=i;
				vis[a[i]]==true;
			}
		}
		for(int i=1;i<=v.size();i++){
			b[v[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
