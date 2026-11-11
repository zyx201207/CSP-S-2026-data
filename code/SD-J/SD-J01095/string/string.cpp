#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll n,suma,hel,her,ans;
ll a[200005],l[30],r[30];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		suma+=a[i];
	}
	if(suma%2==0){
		suma=suma/2;
	}
	else{
		suma=(suma-1)/2;
	}
	ll mid=1;
	ll sumb=suma;
	while(suma>0){
		if(suma-a[mid]>0){
			suma-=a[mid];
			mid++;
		}
		else{
		    suma-=a[mid];	
		}
	}
	for(ll i=1;(i<=mid)&&(hel<sumb);i++){
		l[c[i]-'a'+1]+=a[i];
		hel+=a[i];
	}
	l[c[mid]-'a'+1]+=sumb-hel;
	for(ll i=n;(i>=mid)&&(her<sumb);i--){
		r[c[i]-'a'+1]+=a[i];
		her+=a[i];
	}
	mid++;
	r[c[mid]-'a'+1]+=sumb-her;
	for(ll i=1;i<=27;i++){
		ans+=abs(l[i]-r[i]);
	}
	cout<<ans/2<<endl;
	return 0;
} 
