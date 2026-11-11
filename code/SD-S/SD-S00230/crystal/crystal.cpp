#include<bits/stdc++.h>
#define ll long long
#define CLOSE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
int n,maxx=-1;
ll m,a[500005],cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	CLOSE
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	maxx=max(maxx,0);
	for(int i=2;i<=n;i++){
		cnt+=(i-1)*(a[i]-a[i-1]);
		//cout<<cnt<<" ";
		if(cnt>m) break;
		maxx=max(maxx,i-1);
	}
	cout<<maxx+1;
	return 0;
}
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9

*/
