#include<bits/stdc++.h>
#define N 500005
#define int long long
#define endl '\n'
#define PII pair<int,int>
using namespace std;

int n,m,a[N],s[N],sum,ans;
set<int> st;
map<int,int> ma;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal1.in","r",stdin);
//	freopen("crystal_my.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int j=1;
	for(int i=1;i<=n;i++){
		st.insert(a[i]);
		ma[a[i]]++;
		auto iter=st.end();
		iter--;
		int mx=*iter;
		sum=(mx*(i-j+1))-s[i]+s[j-1];
		while(sum>m&&j<=i){
			ma[a[j]]--;
			if(!ma.count(a[j])) st.erase(a[j]);
			auto iter=st.end();
			iter--;
			int mx=*iter;
			j++;
			sum=(mx*(i-j+1))-s[i]+s[j-1];
		}
		ans=max(ans,i-j+1);
//		printf("tiaoshi:%d %d %d\n",j,i,sum);
	}
	printf("%lld",ans);
	return 0;
}//知颖你太美