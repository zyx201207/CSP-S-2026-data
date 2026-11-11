#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int c[n+2],d[m+1];
	stack<int>e;
	for(int i=1;i<=m;i++){
		d[i]=0;
	}for(int i=1;i<=n;i++){
		cin>>c[i];
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;i++){
			if(d[c[j]]!=0){
				while(e.top() != c[j]){
					d[e.top()]--;
					e.pop();
				}continue;
			}e.push(c[j]);
			d[c[j]]++;
		}while(!e.empty()){
			e.pop();
		}
	}for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}return 0;
}
