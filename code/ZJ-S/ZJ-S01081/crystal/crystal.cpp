#include<bits/stdc++.h>
#define int long long

using namespace std;

int read(){
	int t=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		t=t*10+ch-48;
		ch=getchar();
	}
	return t*f;
}
const int maxn=5e5+10;
int a[maxn];
int pre[maxn];
int n,m;
int ans=1;

bool check(int id,int k){
	if(k==1){
		return 1;
	}
	if(k>id){
		return 0;
	}
	int r=id-1;
	int l=id-k+1;
	int cost=(a[id]*(k-1))-(pre[r]-pre[l-1]);
	return cost<=m;
}

signed main(){
	//finished
	//truly finished
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	
	for(int i=1;i<=n;i++){
		if(i<n&&a[i]==a[i+1])continue;
		int l=1,r=i+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				l=mid+1;
			}else{
				r=mid;
			}
		}
		ans=max(ans,l-1);
	}
	cout<<ans;
	
	return 0;
}
/*
5 5 
1 2 4 8 9
*/