#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],vis[500005],ans[500005];
vector<int> q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			if(vis[i]) ans[i]++;
		}
		if(!vis[i]){
			q.push_back(a[i]);
			vis[i]=1;
		}else{
			int z;
			for(int k=0;k<q.size();k++){
				if(a[k]==a[i]){
					z=k;
					break;
				}
			}
			for(int k=z;k<q.size();k++){
				q.erase(k);
			}
		}
	}
	return 0;
}	     