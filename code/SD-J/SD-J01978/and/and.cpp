#include<bits/stdc++.h>
using namespace std;
int n,m,num,a[500005],s[300005],f[2005][2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s[0]=a[1];
	num=a[1];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]&a[i];
		num=num&a[i];
	}
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==n){
		cout<<num;
		return 0;
	}
	else if(m==2){
		int asd=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				asd=max(asd,a[i]&a[j]);
			}
		}
		cout<<asd;
		return 0;
	} 
	else{
		f[0][1]=a[1];
		f[1][0]=a[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=max(f[i-1][j],max(f[i-1][j-1]&a[i],f[i][j-1]&a[i]));
				//cout<<f[i][j]<<' ';
			}
			//cout<<'\n';
		}
		cout<<f[n][m];
	}
	
	return 0;
}
/*
5 3 
31 3 1 15 7

*/
