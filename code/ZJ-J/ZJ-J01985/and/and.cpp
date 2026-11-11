#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],now[N],nxt[N],ans=0;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1,cmp);
	int r=n;for(int i=1;i<=n;i++){now[i]=a[i];}
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=r;j++){
			if(((now[j]>>i)&1)){nxt[++cnt]=now[j];}
		}
		if(cnt>=m){ans|=(1<<i);for(int j=1;j<=cnt;j++){now[j]=nxt[j];}r=cnt;}
	}
	cout<<ans;
	return 0;
}