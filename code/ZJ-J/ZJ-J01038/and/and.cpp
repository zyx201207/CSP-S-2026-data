#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],maxn;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}	
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;	
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	bool flag1=false;
	for(int i=1;i<=18;i++){
		if(pow(2,i)==n) flag1=true;
	}
	if(flag1==true){
		for(int i=1;i<=n;i++){
			if(a[i]!=i-1){
				flag1=false;
				break;
			}
		}
		if(flag1==true){
			cout<<m*3;
			return 0;
		}
	}
	bool flag=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=18;j++){
			if(pow(2,j)-1==a[i]){
				flag=true;
				break;
			}
		}
		if(flag==false) break;
	}
	if(flag==true){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
	if(flag==false && flag1==false){
		cout<<maxn;
	}
	return 0;
}