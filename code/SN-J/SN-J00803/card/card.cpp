//李沐阳 SN-J00803 西安交通大学附属中学兴庆校区 初一年级
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],am[300010],sum[300010];
void card(long long vi){
	stack<long long> s;
	memset(am,0,sizeof am);
	for(int i=vi;i<=n;i++){
		long long aa=a[i];
		while(am[aa]){
			am[s.top()]--;
			s.pop();
		}
		am[aa]=1;
		s.push(aa);
	}
	for(int i=1;i<=m;i++)if(am[i])sum[i]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=1;i<=n;i++)card(i);
	for(long long i=1;i<=m;i++)printf("%lld ",sum[i]);
	return 0;
}
