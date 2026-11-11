#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
long a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(m==0){printf("1\n");return 0;}
	ll tot=0;
	for(int i=2;i<=n;i++){
		tot+=(ll)(a[i]-a[i-1]);
		if(tot>m){
			printf("%d\n",(i-1));
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
	}printf("%d\n",n);
	return 0;
}