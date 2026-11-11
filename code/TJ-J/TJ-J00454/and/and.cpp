#include<bits/stdc++.h>
using namespace std;
int n,a[100010],m,flag=1;
long long h[10010][10010];
long long f(int x,int y){
	if(y==1)return x;
	if(h[x][y])return h[x][y];
	if(y%2==0){
		h[x][y]=f(x,y/2)*f(x,y/2);
		return h[x][y];
	} 
	h[x][y]=f(x,y/2)*f(x,y/2)*x;
	return h[x][y];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		for(int k=1; k<=30; k++){
			if(f(2,k)!=a[i]+1){
				flag=0;
			}
		}
	}
	if(m==1){
		int maxn=0;
		for(int i=1; i<=n; i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}else if(m==2){
		int ans=-999;
		for(int i=1; i<=n; i++){
			int sum=a[i];
			sum&=a[i+1];
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}else if(flag){
		sort(a+1,a+n+1);
//		for(int i=1; i<=n; i++){
//			cout<<a[i]<<" ";
//		}
		cout<<a[m];
		return 0;
	}
	return 0;
}
