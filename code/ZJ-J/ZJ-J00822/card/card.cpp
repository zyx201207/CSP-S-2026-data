#include <bits/stdc++.h>
using namespace std;
const int inf=300005;
int n,m;
long long a[inf];
stack<long long>q;
long long v[inf];
long long tong[inf];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=1;
	while(t<=n){
		memset(v,0,sizeof(v));
		for(int i=t;i<=n;i++){
			int x=a[i];
			if(v[x]==1){
				while(!q.empty()){
					int y=q.top();
					q.pop();
					if(y==x){
						break;
					}
					q.pop();
				}
			}
			q.push(x);
			v[x]=1;
		}
		while(!q.empty()){
			int x=q.top();
			q.pop();
			tong[x]++;
		}
		t++;
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}