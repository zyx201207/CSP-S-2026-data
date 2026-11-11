#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long int a[500002],b[10001][10001],c[500001];
long long int m; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m<=1000000000){	
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<=n;j++){
				b[i][j]=0;
			}
		}
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
		    long long int cha=a[i]-a[i-1];
		    long long int sum=0;
			for(int j=1;j<i;j++){
				b[i][j]=b[i-1][j]+cha;
				sum+=b[i][j];
			}
			if(sum>m){
				break;
			}
			else{
				ans=max(i,ans);
			}
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		long long int ch=a[2]-a[1];
		long long int sum=0,k=2,e=ch;
		while(sum<=m&&k<=n){
			sum+=e;
			e+=ch;
		}
		cout<<k-1;
	}
	return 0;
}
