#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
map<int,bool> po;
int n,m,mxx;
void dfs(int x,int y,int an){
	if(y>n-x+1)return;
	if(y==0){
		mxx=max(mxx,an);
		return;
	}
	int nxt;
	if(an==0)nxt=a[x];
	else nxt=an&a[x];
	dfs(x+1,y-1,nxt);
	dfs(x+1,y,an);
}
bool f(int n){
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(po.count(a[i]+1)){
			flag=0;
			break;
		}
	}
	return flag;
}
bool g(int n){
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]>3){
			flag=0;
			break;
		}
	}
	return flag;
}
bool h(int n){
	bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			flag=0;
			break;
		}
	}
	return flag;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int p=1;
	while(1){
		p*=2;
		po[p]=1;
		if(p==2147483648)break;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		} 
		cout<<mx;
	}
	else if(m==n){ 
		int x=a[1];
		for(int i=2;i<=n;i++){
			x&=a[i];
		} 
		cout<<x;
	}
	else if(f(n)){
		int x=a[n];
		m--;
		for(int i=n-1;m!=0;i--,m--){
			x&=a[i];
		}
		cout<<x;
	}
	else if(po.count(n)&&h(n)){
		if(m>n/2)cout<<0;
		else{
			int x=a[n];
			m--;
			for(int i=n-1;m!=0;i--,m--){
				x&=a[i];
			}
			cout<<x;
		}
	}
	else if(g(n)){
		int x,y,z;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				x++;
			}
			if(a[i]==2){
				y++;
			}
			if(a[i]==3){
				z++;
			}
		}
		if(m<=z)cout<<3;
		else if(m<=z+y)cout<<2;
		else if(m<=z+x)cout<<1;
		else cout<<0;
	}
	else if(n<=20){
		dfs(1,m,0);
		cout<<mxx;
	}
	else if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				mx=max(mx,a[i]&a[j]);
			} 
		} 
		cout<<mx;
	}
	return 0;
}

