#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans,s1=1,s2;
struct st{
	ll shu;
	char zi;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].shu>>a[i].zi;
	}
	s2=n;
	while(s1<s2){
		ll mi=min(a[s1].shu,a[s2].shu);
		a[s1].shu-=mi,a[s2].shu-=mi;
		if(a[s1].zi!=a[s2].zi)ans+=mi;
		if(a[s1].shu==0)s1++;
		if(a[s2].shu==0)s2--;
	}
	cout<<ans;
	return 0;
}
//i use 25 min to ac problem a and b
