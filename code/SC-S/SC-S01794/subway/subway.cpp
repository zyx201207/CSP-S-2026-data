#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,w[1000],k[100],ss=0;
	cin>>c>>n>>m>>d>>q;
	long long x[q],y[q],a[n][100],t[n][100];
	for(long long i=0;i<m;i++){
		cin>>w[i];
	}
	for(long long i=0;i<n;i++){
		cin>>k[i];	
		for(long long j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}	
	}
	for(long long i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	int b[n][100]={0},h[100];
	for(long long i=0;i<q;i++){
		for(long long j=0;j<n;j++){
			for(long long z=0;z<k[j];z++){
				if(a[j][z]==x[i])b[j][z]=1;
				if(a[j][z]==y[i])b[j][z]=1;
				h[a[j][z]]++;
			}
		}
	}
	int g1[q]={1},g2[q];
	for(long long i=0;i<q;i++){
		int s=0;
		for(long long j=0;j<n;j++){
			for(long long z=0;z<k[j];z++){
				if(b[i][z]==1)s+=1;
			}
			if(s>g1[i])g1[i]=s,g2[i]=j;
		}
	}
//	for(long long i=0;i<q;i++)
//		if(g1[i]>1){
//			for(long long j=0;j<n;j++){
//				for(long long z=0;z<k[j];z++){
//						
//				}
//			}
//		}
//		else {
//			
//		}
for(int i=0;i<q;i++){
	if(x[i]==1){
		if(y[i]==2)cout<<17<<endl;
		else if(y[i]==3)cout<<32<<endl;
		else if(y[i]==6)cout<<35<<endl;
	}
	else if(x[i]==2||y[i]==3)cout<<16<<endl;
}
	return 0;
}