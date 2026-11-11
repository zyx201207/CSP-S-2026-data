#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,m,a[N],ans[N],lst[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
