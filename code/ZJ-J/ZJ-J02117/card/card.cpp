#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],st[M],ans[M],p[N],n,m;

void solve(int k){
	memset(st,0,sizeof(st));
	int l=0;
	for(int i=k;i<=n;i++){
//		p[++l]=a[i];
		if(st[a[i]]!=0){
			l=st[a[i]];
		}else l++;
		p[l]=a[i];
		st[a[i]]=l;
	}
	for(int i=1;i<=l;i++){
//		cout<<'t'<<p[i]<<' ';
		ans[p[i]]++;
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

