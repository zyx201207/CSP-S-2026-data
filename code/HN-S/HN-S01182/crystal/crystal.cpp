#include<bits/stdc++.h>
using namespace std;

using i64 = long long ;

const int N = 5e5 + 2 ;

int n;
i64 m;
i64 a[N];

int main(){
	//
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	int j=0;
	i64 tot=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		tot+=a[i];
		while(a[i]*(i-j)-tot>m){
			j++;
			tot-=a[j];
		}
		if(i-j>ans)
			ans=i-j;
	}
	printf("%d",ans);
	return 0;
}

