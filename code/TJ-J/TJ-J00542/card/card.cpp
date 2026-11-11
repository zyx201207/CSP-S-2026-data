#include<bits/stdc++.h>
using namespace std;
int d[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500010];
	string v;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<=n;j++){
			bool u=0;
			for(auto c:v){
				if(u==1){
					v.pop_back()
				}
				if(c==a[j]){
					u=1;
				}
			}
			if(u==0)v.push_back([j]);
		}
		for(auto c:v){
			d[c]++;
		}
		v.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
} 
