#include<bits/stdc++.h>
using namespace std;
const long long N=0;
int n,m;
int a[500005],c[500005],b[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	 	cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool flag=1;
	int fl=a[2]-a[1];
	for(int i=1;i<=n;i++){
	 	int dt=a[i]-a[i-1];
	 	if(fl!=dt&&i!=1)flag=0;
		 if(i!=1){
	 		b[i]=dt+b[i-1];
		 }
	 	c[i]=dt*(i-1)+c[i-1];
	}
	if(flag){
		cout<<m/fl;
		return 0;
	}
//	if(n>5000&&n<=500005){
//		
//	}
	int maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int sum=c[j];
			for(int k=1;k<i;k++){
				sum-=(b[j]-b[i]);
			}
			if(sum<=m){
				maxx=max(maxx,j-i+1);
			}
		}
	}
	cout<<maxx;
	return 0;
} 
