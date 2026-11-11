#include<bits/stdc++.h>
using namespace std;
int m,n,c[500000],a[300000],used[500000];
stack<int>b;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		memset(used,0,sizeof(used));
		for(int j=i;j<n;j++){
			if(used[c[j]]){
				while(b.top()!=c[j]){
					used[b.top()]=0;
					b.pop();
				}
				b.pop();
			}
			used[c[j]]=1;
			b.push(c[j]);
		}
		while(!b.empty()){
			a[b.top()]++;
			b.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
