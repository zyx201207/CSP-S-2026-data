#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t;
ll n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c>>t;
	if(1){
		for(int i=1;i<=t;i++)
		{	
			cin>>n>>k;
			for(int i=1;i<=n-1;i++)
			{
				int u,v;
				cin>>u>>v;
			}
			ll ans=LLONG_MAX;
			cout<<(int(log2(n<<1-1))+1)/2;
		}
	}
	return 0;
}
/*
14:28 CCF还是太幽默了（Oct31==Dec25?）
14:30 开考！（监考员：开始搞事）
14:37 在名单上看到了 ruyingsuixing
14:49 T1 AC
16:53 Process exited after 7.891 seconds with return value 0
17:49 卡常=上吊（T2）
18:02 T2 AC（getchar_unlocked?）
18:23 放弃挣扎，200pts。
*/ 
