#include <bits/stdc++.h>
using namespace std;
int n;
long long m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n ,&m);
	vector<long long>a(n+1);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a.begin(),a.end());
	int sum=0;
	for(int i=2;i<=n;i++){int b=0;int x=1,ji=a[i-x];
	for(int j=m;j>0;){
		j-=(a[i]-ji);
		if(j>=0)
		ji=a[i];
		if(ji>a[i]){b++;j++;x++;ji=a[i-x];}
		if(ji==a[i]){b++;if(x==i-1){j=0;break;}else {x++;ji=a[i-x];}}		
	}b++;sum=max(sum,b);
	}
	printf("%d",sum);
	return 0;
	}
