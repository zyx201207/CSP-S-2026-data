#include<bits/stdc++.h>
using namespace std;
int n,m,k[300010],a[500010];
queue<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			q.push(a[i]);
		}
	}
	while(!q.empty()){
		k[q.front()]++;
		q.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<k[i]<<' ';
	}
	return 0;
}
