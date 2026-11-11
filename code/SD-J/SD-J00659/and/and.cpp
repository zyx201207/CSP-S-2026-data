#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mi=1,ma=0,maxx=0,cnt=0,x=0,j=0,maa=0,cn=0,g[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);	
	}
	cnt=a[1];
	for(int i=1;i<=n;i++){
		cnt&=a[i];	
	}
	if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==1){
		cout<<ma;
		return 0;
	} 
	if(m==n){
		cout<<cnt;
		return 0;
	}
	cout<<0;
	return 0;
} 
