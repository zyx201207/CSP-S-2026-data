#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int t[N];
int c[N];
bool v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=1;
		}
	}
	if(f==0){
		for(int i=1;i<=m;i++){
			int j=1;
			while(j<=n){
				if(a[j]==i){
					j++;
				}
			}
			cout<<j-1<<" ";
		}
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		memset(v,0,sizeof v);
		for(int j=i;j<=n;j++){
			bool flag=0;
			for(int k=1;i<=cnt;i++){
				if(t[k]==a[j]){
					flag=1;
					cnt=k;
					break;
				}
			} 
			if(flag==0){
				t[++cnt]=a[j];
			}
		}
		for(int j=1;j<=cnt;j++){
			v[t[j]]=1;
		}
		for(int j=1;j<=m;j++){
			if(v[j]==1){
				c[j]++;
			} 
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

