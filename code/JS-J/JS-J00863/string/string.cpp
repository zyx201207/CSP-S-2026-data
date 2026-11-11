#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
struct str{
	char letter;
	ll num;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll sum=0;
	string temp="";
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].letter;
		sum+=a[i].num;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].num;j++){
			temp+=a[i].letter;
		}
	}
	ll ans=0;
	ll pos;
	if(sum%2==0) pos=sum/2;
	else pos=sum/2+1;
	for(ll i=0;i<sum/2;i++){
		if(temp[i]!=temp[pos+i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
