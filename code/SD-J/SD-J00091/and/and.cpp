#include<bits/stdc++.h>
using namespace std;
int a[100005],n,m;
int maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]||a[i]==a[i+1]){
			continue;
		}
		else{
			maxx=max(a[i]|a[i+1],a[i]|a[i-1]);
		}
	}
	cout<<maxx;
	return 0;
}
//4 2
//3 15 12 12
//5 3
//31 3 1 15 7
