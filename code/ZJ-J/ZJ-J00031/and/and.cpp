#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long arr[N];
int xuan[30];
long long ansd=0;
void dfs(int x,int n,int m){
	if(x==n+1){
		long long cnt=0;
		int f=0;
		for(int i=1;i<=n;i++){
			if(xuan[i]==2){
				if(f==0){
					cnt=arr[i];
				}else{
					cnt=(cnt&arr[i]);
					
				}
				f++;
			}
		}
		if(f==m) ansd=max(ansd,cnt);
		return;
	}
	xuan[x]=1;
	dfs(x+1,n,m);
	xuan[x]=2;
	dfs(x+1,n,m);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n<=20){
		dfs(1,n,m);
		cout<<ansd;
		return 0;
	}
	if(m==1){
		long long mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,arr[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		long long ansm=arr[1];
		for(int i=2;i<=n;i++){
			ansm=(ansm&arr[i]);
		}
		cout<<ansm;
		return 0;
	}
	if(m==2&&n<=2000){
		long long anst=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long a=i;
				long long b=j;
				anst=max(anst,(arr[a]&arr[b]));
			}
		}
		cout<<anst;
		return 0;
	}else{
		sort(arr+1,arr+1+n);
		long long ansh=arr[n];
		for(int i=n-1;i>=n-m+1;i--){
			ansh=(ansh&arr[i]);
		}
		cout<<ansh;
		return 0;
	}
	return 0;
}
