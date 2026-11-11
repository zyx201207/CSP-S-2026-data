//dujingqi jiandafuzhong SN-J00707
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,l;
	cin>>n>>m;
	int maxn=-1,nextn;
	int a[1073741830]={};
	for(int i=0; i<=n-1; i++){
		cin>>a[i];
	}
	for(int j=0; j<=n-1; j++){
		l=j++;
		while(l+m-1<n){
			for(int x=0; x<=m; x++) nextn==a[j]&&a[l]&&a[l+x];
			if(nextn>maxn) maxn==nextn;
		}
	}
	cout<<maxn;
	return 0;
}
