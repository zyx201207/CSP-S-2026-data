#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N],b[M],c[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=false;
	}
	if(flag){
		for(int i=1;i<=n;i++) c[a[i]]=i;
		for(int j=1;j<=m;j++) cout<<c[j]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) b[j]=0;
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(s.top()!=a[j]){
					b[s.top()]=0;
					s.pop();
				}
			}else{
				b[a[j]]=1;
				s.push(a[j]);
			}
		}
		for(int j=1;j<=m;j++) c[j]+=b[j];
	}
	for(int j=1;j<=m;j++) cout<<c[j]<<' ';
	return 0;
} 
