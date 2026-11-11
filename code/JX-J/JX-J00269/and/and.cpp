#include<bits/stdc++.h>
using namespace std;
long long n,m,m1,a,b[200001][51],zc,jl[200001],s,zb[200001],x=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++){
		cin>>a;
		long long cd=1;
		while(a!=0){
			b[i][cd]=a%2;
			a/=2;
			cd++;
		}
		zc=max(zc,cd-1);
	}
	for(int j=zc;j>=1;j--){
		s=0;
		for(int i=1;i<=n;i++){
			if(jl[i]==0){
				if(b[i][j]==1){
					s++;
				}
			}
		}
		if(s==m){
			for(int i=1;i<=n;i++){
				if(b[i][j]==1 and jl[i]==0){
					zb[x]=i;
					x++;
				}
			}
		}else if(s>m){
			for(int i=1;i<=n;i++){
				if(b[i][j]==0){
					jl[i]=1;
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(b[i][j]==1 and jl[i]==0){
					zb[x]=i;
					x++;
					jl[i]=1;
				}
			}
			m-=s;
		}
		if(j==1 and x-1!=m1){
			for(int i=1;i<=n;i++){
				if(jl[i]==0 and x-1!=m1){
					zb[x]=i;
					x++;
				}
			}
		}
	}
	for(int i=1;i<x-1;i++){
		for(int j=1;j<=zc;j++){
			if(b[zb[i]][j]==1 and b[zb[i+1]][j]==1){
				b[zb[i+1]][j]=1;
			}else{
				b[zb[i+1]][j]=0;
			}
		}
	}
	long long ans=0,bei=1; 
	for(int i=1;i<=zc;i++){
		ans=ans+b[zb[x-1]][i]*bei;
		bei*=2;
	}
	cout<<ans;
	return 0;
}
















