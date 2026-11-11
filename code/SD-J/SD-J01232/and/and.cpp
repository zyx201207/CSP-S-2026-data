#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[200005],maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1) cout<<maxx;
	if(m==n){
		int b=a[1];
		for(int i=2;i<=n;i++){
			b=b&a[i];
		}cout<<b;
	} 
	return 0;
}
