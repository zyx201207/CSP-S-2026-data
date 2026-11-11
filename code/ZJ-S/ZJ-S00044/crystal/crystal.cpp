#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+5;
int n;
ll m,a[N],q[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		q[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++){
		if(m<q[i]*(i-1)){
			printf("%d\n",i-1);
			return 0;
		}
		m-=q[i]*(i-1);
	}
	printf("%d\n",n);
	return 0;
}