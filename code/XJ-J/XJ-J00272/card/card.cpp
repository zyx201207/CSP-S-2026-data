#include<bits/stdc++.h>
using namespace std;
int a[600000],b[400000],d[400000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stack<int>c;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(d[a[j]]==1){
				while(c.top()!=a[j]){
					d[c.top()]=0;
					c.pop();
				}
			}
			else{
				c.push(a[j]);
				d[a[j]]=1;
			}
		}
		for(int k=1;k<=m;k++){
			if(d[k]==1){
				b[k]++;
			}
			d[k]=0;
		}
		while(!c.empty()){
			c.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
}
