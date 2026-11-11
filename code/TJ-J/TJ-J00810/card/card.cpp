#include<bits/stdc++.h>
using namespace std;
int a[500005];
int tong[500005];
int v[500005];
stack<int>c;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,o=1,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(tong[a[j]]==0){
				tong[a[j]]=1;
				c.push(a[j]);
			}
			else{
				while(c.top()!=a[j]){
					tong[c.top()]=0;
					c.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(tong[j]!=0){
				v[j]++;
			}
		}
		while(!c.empty()){
			c.pop();
		}
		for(int j=1;j<=n;j++){
			tong[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
