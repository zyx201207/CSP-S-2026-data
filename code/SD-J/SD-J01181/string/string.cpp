#include<bits/stdc++.h>
using namespace std;
//const int INF=0x7FFFFFFF;
const int N=2E5+10;
#define ll long long
ll n;
ll ans;
struct sdig{
	ll consting;
	char name;
}a[N]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld %c",&a[i].consting,&a[i].name);
//	cout<<"---1---\n"; 
	for(int i=1,j=n;i<j;){
		if(a[i].consting==a[j].consting){
			if(a[i].name!=a[j].name)
				ans+=a[i].consting;
			i++,j--;
		}
		else if(a[i].consting>a[j].consting){
			if(a[i].name!=a[j].name)
				ans+=a[j].consting;
			a[i].consting-=a[j].consting;
			j--;
		}
		else{
			if(a[i].name!=a[j].name)
				ans+=a[i].consting;
			a[j].consting-=a[i].consting;
			i++;
		}
	}
//	cout<<"---2---\n";
	printf("%lld",ans);
	return 0;
}
