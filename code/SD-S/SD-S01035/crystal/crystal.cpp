#include<bits/stdc++.h>
#define ll long long
#define up(_i,_l,_r) for(auto _i=(_l);_i<=(_r);_i++)
#define dn(_i,_r,_l) for(auto _i=(_r);_i>=(_l);_i--)
using namespace std;
const int N=5e5+5,M=2e5+5;
const int inf=0x3f3f3f3f,mod=1e9+7;
ll n,m;
ll a[N];
int x;
ll sum=0;
int ans;
void Main(){
	scanf("%lld%lld",&n,&m);
	up(i,1,n) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	x=ans=1;
	up(i,2,n){
		sum=sum+(a[i]-a[i-1])*(i-x);
		while(sum>m&&x<=i){
			sum-=(a[i]-a[x]);
			x++;
		}
		ans=max(ans,i-x+1);
	}
	printf("%d\n",ans);
}
/*
T1题意：给出序列，对序列进行操作至多m次，每次将一个数+1
问最多能有多少个数相同 
显然，最终的相同值一定在序列中出现过
原因：如果没出现过，可以都少操作，变成一个序列中的值
不妨枚举这个值，即所有数都变成a[i]
我们对序列排序，这样最终变成a[i]的一定是区间[j,i]
随着i增加1，j是不降的，因为[j,i]里所有数都要变多
(a[i]-a[i-1])*((i-1)-j+1) 
这是>0的，因此维护一个j指针即可
现在是15:48，我回来写T1了 
15:54过大样例 
*/
signed main(){
	if(1){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
	}
	int Test=1;
//	scanf("%d",&Test);
	while(Test--){
		Main();
	}
	return 0;
}

