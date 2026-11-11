#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005]={};
int s[500005]={};
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	a[0]=-2e17-1;
	int i=1,j=1;
	int max1=1;
	int mi=1;
	while(i>0&&j<=n){
		max1=max(max1,j-i+1);
		int r=a[j+1]*(j-i+2)-s[j+1]+s[i-1];
		while(r>m){
			i++;
			r=a[j+1]*(j-i+2)-s[j+1]+s[i-1];
		}
		if(r<=m&&j!=n){
			j++;
		}else if(j!=n){
			i++;
		}else{
			break;
		}
	}
	cout<<max1;
	return 0;
} 
