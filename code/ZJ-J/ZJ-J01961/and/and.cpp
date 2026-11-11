#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
long long a[200005];
bool b[200005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n,cmp);
	int ans=a[0];
	for(int i=1;i<m;i++){
		ans=ans&a[i];
	}
	printf("%lld",ans);
	return 0;
 } 
