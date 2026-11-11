#include<bits/stdc++.h>
using namespace std;
freopen("card.in","r",stdin)
freopen("card.out","w",stdout)
int n,m;
int a[500005];
int b[300005];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;i<=n;i++){
				cout<<"i:"<<i<<"j:"<<j;
				if(v[a][j]==0){
					q.push_back(a[j]);
					v[a[j]=1];
				}
				else{
					while(!q.empty()){
						int t=q.back();
						v[q.front()]=0;
					}
						q.push[a[j]];
					}
				while(!q.empty()){
					int t=q.front();
					q.pop();
			}
			for(int i=1;i<=m;i++){
				cout<<b[i]<<
			}
		}
		for(int i=)
		
	}
	return 0;
}
