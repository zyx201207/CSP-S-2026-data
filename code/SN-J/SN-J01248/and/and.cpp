#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;

int n,m;
int a[N];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int b=29;b>=0;b--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((a[i]&(ans|(1<<b))) == (ans|(1<<b))){
				cnt++;
			}
		}
		if(cnt>=m)ans|=1<<b;
	}
	printf("%lld",ans);
	return 0;
}
