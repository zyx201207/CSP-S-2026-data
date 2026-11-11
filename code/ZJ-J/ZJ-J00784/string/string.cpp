#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+20;
struct piece{
	ll len;
	char s;
}a[N],b[N];
ll n,t,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].s;
		b[n-i+1]=a[i];
	}
	t=0;l=1;
	for(int i=1;i<=n;i++){
		if(b[i].s==a[l].s&&b[i].len<=a[l].len){
			a[l].len-=b[i].len;
			continue ;
		}
		if(b[i].s!=a[l].s&&b[i].len<=a[l].len){
			t+=b[i].len;
			a[l].len-=b[i].len;
			continue ;
		}
		if(b[i].s==a[l].s&&b[i].len>=a[l].len){
			b[i].len-=a[l].len;
			i--;
			l++;
			continue ;
		}
		if(b[i].s!=a[l].s&&b[i].len>=a[l].len){
			t+=a[l].len;
			b[i].len-=a[l].len;
			i--;
			l++;
			continue ;
		}
		
	}
	cout<<t/2;
	return 0;
}
