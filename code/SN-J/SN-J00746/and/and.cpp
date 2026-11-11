//SN-J00746 张宸熙 西安市第十二中学 
#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(n==m){
		long long s=a[1];
		for(int i=2;i<=n;i++){
			s=s&a[i];
		}
		cout<<s;
		return 0;
	}
	if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=a[i]&a[j];
				maxx=max(maxx,t);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1){
		long long maxx=0;
		long long k=a[2];
		for(int i=3;i<=n;i++){
			k=k&a[i];
		}
		for(int i=2;i<=n;i++){
			long long s=a[1];
			for(int j=2;j<=n;j++){
				if(j!=i){
					s=s&a[i];
				}	
			}
			maxx=max(maxx,s);
		}
		maxx=max(k,maxx);
		cout<<maxx;
		return 0;
	}
	int s=0;
	for(int i=1;i<=m;i++){
		int maxx,id;
		maxx=0,id=0;
		for(int j=1;j<=n;j++){	
			if(a[j]>maxx){
				maxx=a[j];
				id=j;
			}
		}
		a[id]=0;
		if(s==0){
			s=maxx;
		}else{
			s=s&maxx;
		}
	}
	cout<<s;
}
