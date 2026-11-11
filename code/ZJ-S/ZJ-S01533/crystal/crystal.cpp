#include <bits/stdc++.h>  // RP++!
using namespace std;
typedef long long ll;
const int N = 5e5 + 100;
struct node{
	ll x,y;
}nodes[N];
int n,l = 0;
ll m;
ll a[N],b[N],nums[N],sums[N];
//ll cost[N];
map<ll,ll> mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
		if(!mp[a[i]])
			b[++l] = a[i],mp[a[i]] = 1;
		else
			mp[a[i]]++;
	}
	sort(b+1,b+l+1);
	for(int i = 1;i <= l;i++)
		nodes[i].x = b[i],nodes[i].y = mp[b[i]];
//	for(int i = 1;i <= l;i++)
//		printf("%lld %lld\n",nodes[i].x,nodes[i].y);
//	for(int i = 2;i <= l;i++)
//		cost[i] = (nodes[i].x - nodes[i-1].x) * nodes[i-1].y;
	nums[0] = 0,sums[0] = 0;
	for(int i = 1;i <= l;i++){
		nums[i] = nums[i-1] + nodes[i].y;
		sums[i] = sums[i-1] + nums[i-1] * (nodes[i].x - nodes[i-1].x);
	}
	int maxn = 0,ans = 0;
	int head = 1,tail = 1;
	ll cur = 0;
	for(;tail <= l && sums[tail] <= m;tail++)
		ans = nums[tail],maxn = ans;
	cur = sums[tail-1];
	for(;tail <= l;tail++){
		cur += ans * (nodes[tail].x - nodes[tail-1].x);
		ans += nodes[tail].y;
//		cout<<cur<<' '<<ans<<' ';
		while(cur > m){
			int x = nodes[tail].x - nodes[head].x;
			ll cnt = ceil(1.0 * (cur - m) / x);
			if(cnt >= nodes[head].y)  // Í·¼õÍê 
				cur -= x * nodes[head].y,ans -= nodes[head++].y;
			else
				cur -= x * cnt,ans -= cnt,nodes[head].y -= cnt;
//				break;
		}
		maxn = max(maxn,ans);
//		cout<<ans<<endl;
	}
	cout << maxn;
	return 0;
}
/*
sample 1
5 5
1 2 4 8 9
output:3
0 1 2 4 1 cost
1 2 3 4 5 nums
0 1 5 17 21 sums

sample 2
5 8
-3 -1 2 2 7
output:4
0 2 3 10 cost
1 2 4 5 nums
0 2 8 28 sums

sample 3
output:3845

sample 4:
output:315275
*/
