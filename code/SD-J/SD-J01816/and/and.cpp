#include<bits/stdc++.h>
#include<cstdio>
#define int unsigned long long
using namespace std;
const int N=2e5+10;
int maxn=-1e9,cnt=0;
int n,m;
int a[N],b[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
} 
