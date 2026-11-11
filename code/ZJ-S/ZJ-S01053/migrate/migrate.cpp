#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long c,T,x1,x2,xl,l;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		long long n,d;
		cin>>n>>d;
		cin>>x1>>x2;
		for(int i=3;i<=n;i++)scanf("%d",&l);
		xl=x2-x1;
		long long t=d/xl;
		if(t>=2 && 2*t<=n)printf("%d",n-2*t+1);
		else printf("0");
	}
	return 0;
}
