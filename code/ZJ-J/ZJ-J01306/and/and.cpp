#include<bits/stdc++.h>
using namespace std;
long long n,m,a[214514],ans=0,t[40];
int b[214514][40];
bool bo[214514]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m; 
	t[1]=1; 
	for(int i=2;i<=33;i++) t[i]=t[i-1]*2; 
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long cnt=0;
		while(a[i]>0){
			b[i][++cnt]=a[i]%2;
			a[i]/=2; 
		}
	}
	for(int i=32;i>=1;i--){
		long long cnt=0; 
		for(int j=1;j<=n;j++){
			if(bo[j]==0 && b[j][i]==1) cnt++; 
		}
		if(cnt>=m){
			ans+=t[i];
			for(int j=1;j<=n;j++){
				if(b[j][i]==0) bo[j]=1; 
			}
		} 
	} 
	cout<<ans; 
	return 0;
}
