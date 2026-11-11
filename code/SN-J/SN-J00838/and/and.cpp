#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int v[m];
	for(int u=0;u<n;u++){
		long long b[n];
		int p=0;
		int g=0;
		for(int i=u;i<n;i++){
			for(int j=0;j<i;j++){
				if(b[j]==0 || b[j]==a[i]) continue;
				else g++;
			} 
			if(g==p){
				b[i]==a[i];
				p++;
			} 
			else{
				for(int j=0;j<n;j++){
					if(b[j]==a[i]){
						for(int h=j;h<=p;h++){
							b[h]=0;
						}
						b[j]=a[i];
						continue;
					} 
				}
			} 
		}
		int y=0;
		for(int i=0;i<n;i++){
			if(b[i]!=0) y+=b[i];
		}
		v[y]++;		
	}
	for(int i=1;i<=m;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
