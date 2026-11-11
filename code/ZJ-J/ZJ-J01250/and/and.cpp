#include<bits/stdc++.h>
using namespace std;
int m,n,a[300000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(m==1) cout<<a[1];
	else if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans & a[i];
		}
		cout<<ans<<endl;
	}
	else if(m==n-1){
		int maxx=0;
		for(int i=1;i<=n;i++){
			int ans;
			if(i!=1) ans=a[1];
			else  ans=a[2];
			for(int j=1;j<=n;j++)
				if(j!=i){
					ans=ans&a[j];
				}
			maxx=max(ans,maxx);	
		}
		cout<<maxx;
	}
	else{
		int maxx=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				maxx=max(maxx,a[i]&a[j]);
		cout<<maxx;		
	}
	return 0;
}
