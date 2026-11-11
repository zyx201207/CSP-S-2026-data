#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> a;
int main() {
	freopen("crystsl.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,r=0;
	bool e=false;
	ll m,ai;
	scanf("%d %lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&ai);
		a.push_back(ai);
	}
	sort(a.begin(),a.end());
	for(int ii=0;ii<n;ii++)
	for(int i=0;i<n;i++){
		int mi=m;
		for(int j=0;j<i;j++){
			mi-=a[i]-a[j];
			if (mi>=0) continue;
			if (i-ii>r)r=i-ii;
			e=true;
			break;
		}
		if(e)break;
	}
	printf("%d\n",r);
	return 0;
}
