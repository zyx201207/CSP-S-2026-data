#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=-1145141919;
long long a[200005];
bool b[200005];
void dfs(long long x,long long cnt){
	if(cnt==m){
		mx=max(mx,x);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			dfs(x&a[i],cnt+1);
			b[i]=0;
		}
	}
}
int cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}else if(m==2){
		mx=-2147483647;
		long long k;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				k=(a[i]&a[j]);
				mx=max(k,mx);
			}
		}
		cout<<mx;
		return 0;
	}else if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=(a[i] & a[i-1]);
		}
		cout<<a[n];
		return 0;
	}else if(n<=1000){
		mx=-2147483647;
		dfs(2147483647,0);
		cout<<mx;
	}else{
		sort(a+1,a+1+n,cmp);
		for(int i=2;i<=m;i++){
			a[1]&=a[i];
		}
		cout<<a[1];
	}
	return 0;
}