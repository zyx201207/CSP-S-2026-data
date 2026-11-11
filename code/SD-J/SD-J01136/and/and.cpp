#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],b[200001][32],f[200001],ss=1,ans[32],sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int c=31;
		while(a[i]){
			if(a[i]%2)
				b[i][c]=1;
			a[i]/=2;
			c--;}
	}
	for(int i=0;i<=31;i++){
		int s=0;
		for(int j=1;j<=n;j++){
			if(b[j][i]&&f[j]==0)
				s++;}
		if(s>=m){
			ans[i]=1;
			for(int j=1;j<=n;j++){
				if(!b[j][i])
					f[j]=1;}
		}
	}
	for(int i=31;i>=0;i--){
		if(ans[i])
			sum+=ss;
		ss*=2;}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
