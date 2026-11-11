#include<bits/stdc++.h>
using namespace std;
long long n,l,r,ans;
pair<long long,char> a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i].first,&a[i].second);
	}
	l=1,r=n;
	while(l!=r){
		if(a[l].first<a[r].first){
			if(a[l].second!=a[r].second){
				ans+=a[l].first;
			}
			a[r].first-=a[l].first;
			l++;
		}
		else{
			if(a[l].second!=a[r].second){
				ans+=a[r].first;
			}
			a[l].first-=a[r].first;
			r--;
		}
	}
	printf("%lld",ans);
	return 0;
}

