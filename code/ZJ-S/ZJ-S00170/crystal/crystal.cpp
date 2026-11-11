#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500010;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int lst=1;//lst表示 m 次操作能到达的最左的位置
	//易证,lst只增不减，所以复杂度O(n)
	int sum=0;
	int miku=0;
	for(int i=1;i<=n;i++){
		sum+=(i-lst)*(a[i]-a[i-1]);
		while(lst<=i && sum>m){
			sum-=(a[i]-a[lst]);
			lst++;
		}
		miku=max(miku,i-lst+1);
	}
	cout<<miku<<"\n";
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/