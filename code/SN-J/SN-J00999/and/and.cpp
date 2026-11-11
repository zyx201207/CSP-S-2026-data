//AC? 0~100 
#include<bits/stdc++.h>
#define fri(x,y) for(int i = x;i <= y;i++)
#define frj(x,y) for(int j = x;j <= y;j++)
#define MAXN 400000 + 10
#define lihaoming 0
#define ll long long
using namespace std;
int n,m;
ll a[MAXN];
bool cmp(ll x,ll y){
	return x > y;
}
ll ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ans = INT_MAX;
	cin>>n>>m;
	fri(1,n){
		cin>>a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	fri(1,m){
		ans &= a[i]; 
	}
	cout<<ans;
	return lihaoming;
}
/*

mind
考虑到求最大值时应以最大数作为 m 个数之中 
所以可以先 sort a 数组，ax > ay，再进行按位与 
例如： 
5 3
32(100000)
31(011111)
16(010000)
15(001111)
10(001010)
ans = 100000 且最大 

*/
