#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	int c,n,m,d,p;
	int s1[2],s2[2],s3[2],s4[2];
	
	cin>>c>>n>>m>>d>>p;
	int a[m+1],k[n+1],k1[n+1][n+1],k2[n+1][n+1],x[p+1],y[p+1],t[p+1]={0};
	
	
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>k1[i][j]>>k2[i][j];
		}
	}
	for(int i=1;i<=p;i++) cin>>x[i]>>y[i];
	
	
	int s5[100],s6[100],ts=1,l=1;
	for(int i=1;i<=n-1;i++){
		for(int s=i+1;s<=n;s++){
			for(int j=1;j<=k[i];j++){
				if(k1[i][l]==k1[s][j]){
					s5[ts]=i;s6[ts]=j;
					ts++;
				}
			}
		}
		l++;
	}
	
	
	for(int t=1;t<=p;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k[i];j++){
				if(x[t]==k1[i][j]){
					s1[t]=i,s2[t]=j;
				}
				if(y[t]==k1[i][j]){
					s3[t]=i;s4[t]=j;
				}
			}
		}
	}
	
	
	for(int i=1;i<=p;i++){
		if(s1[i]==s3[i]){
			t[i]+=a[s2[i]];
			for(int j=s2[i];j<=s4[i];j++){
				t[i]+=k2[s1[i]][j];
			}
		}
	}
	
	
	for(int i=1;i<=p;i++){
		cout<<t[i]<<endl;
	}
	return 0;
}
