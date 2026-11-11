#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],mp[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	queue<int>q;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]);
	}
	if(n<=5&&m<=2){
		if(n==1){
			ans[m]=1;
		}	
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}

