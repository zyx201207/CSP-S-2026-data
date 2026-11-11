#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500010],la[300010],a[500010],ans[300010];
stack<long long> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		c[a[i]]++;
		if(la[a[i]]==0){
			la[a[i]]=i;
		}
		else{
			la[a[i]]=i;
		}
	}
	sort(la+1,la+m+1);
	for(int i=1;i<=m;i++){
		ans[a[la[i]]]=c[a[la[i]]];
		c[a[la[i]+1]]+=c[a[la[i]]];
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}

