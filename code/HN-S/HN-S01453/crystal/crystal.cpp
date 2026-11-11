#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int r=1,l=n,MaX=0;
	while(r<=l){
		long long q=0;
		for(int i=r;i<=l;i++){
			q=q+(a[l]-a[i]);
		}
		if(q>m){
			l--;
		}else{
			MaX=max(MaX,l-r+1);
			r++;
			l=n;
		}
	}
	cout<<MaX;
	return 0;
}
