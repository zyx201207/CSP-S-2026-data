#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

pair<ll,char>a[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		scanf("%lld %c",&a[i].first,&a[i].second);
	} 
	ll i=1;
	ll j=n;
	ll cnt=0;
	while(1){
		ll l=a[i].first,c=a[j].first;
		char lll=a[i].second;
		char cc=a[j].second;
		if(l>c){
			if(lll!=cc){
				cnt+=c;
			}
			l-=c;
			c=0;
		}else{
			if(lll!=cc){
				cnt+=l;
			}
			c-=l;
			l=0;
		}	
//		printf("i:%lld,j:%lld,l:%lld,c:%lld\n",i,j,l,c);
		if(i>=j)break;
		a[i].first=l;
		a[j].first=c;
		
		if(l==0)i++;
		if(c==0)j--;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
