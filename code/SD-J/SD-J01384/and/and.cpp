#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N];
int fun(int i,int t,int q){
	if(t==m) return q;
	if(i==n+1) return -1;
	if(t==0) return max(fun(i+1,1,a[i]),fun(i+1,0,0));
	return max(fun(i+1,t+1,q&a[i]),fun(i+1,t,q));
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(n<=20){
		cout<<fun(1,0,0);
	}
	else if(n<=2000&&m==1){
		cout<<maxx;
	}
	else if(n<=2000&&m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	else if(n==m){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	} 
	else if(n==m+1){
		sort(a+1,a+1+n);
		int ans=a[2];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(maxx<4){
		int t[10]={0};
		for(int i=1;i<=n;i++){
			t[a[i]]++;
		}
		if(t[3]>=m) cout<<3;
		else if(t[3]+t[2]>=m) cout<<2;
		else if(t[3]+t[1]>=m) cout<<1;
		else cout<<0;
	}
	else if(pow(2,log2(n))==n){
		
	}
	else{
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

