#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200009],ans,b[33],m=30,c[200009],d[200009],cnt;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],c[++cnt]=a[i];
	for(int i=1;i<=n;i++){
		for(int j=30;j>=0;j--){
			if((a[i]>>j)&1) b[j]++;
		}
	}
	while(m>=0){
		while(m>=0&&b[m]<k) m--;
		if(m<0) break;
		ans^=(1<<m);
		for(int i=1;i<=cnt;i++) d[i]=c[i];
		int cnt1=0;
		for(int i=m-1;i>=0;i--) b[i]=0;
		for(int i=1;i<=cnt;i++){
			if((d[i]>>m)&1){
				c[++cnt1]=d[i];
				for(int j=m-1;j>=0;j--){
					if((d[i]>>j)&1) b[j]++;
				}
			}
		}
		cnt=cnt1;
		m--;
	}
	cout<<ans;
	
	
	
	
	return 0;
}
/*
³æÐè
ÔÆÁ¦
°×É×
³æÇÒ 
*/ 
