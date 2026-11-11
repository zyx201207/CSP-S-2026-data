#include<bits/stdc++.h>
using namespace std;
long long n,m,s=0,c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long a[n+10],k[n+10][n+10]={0},shu[n+10]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			k[i][j]=a[j]-a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			shu[i]+=k[j][i];
		}
	}
	s=1;
	for(int i=2;i<=n;i++){
		if(shu[i]<=m){
			s++;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
