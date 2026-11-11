#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
string s;
ll n,sum,ans;
ll t[114514];
char c[114514];
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>c[i];
		sum+=t[i];
		for(int l=1;l<=t[i];l++) s+=c[i];
	}
	//cout<<s<<" "<<sum;
	ll l=0,r=sum-1;
	while(l<r){
		if(s[l]!=s[r]) ans++;
		l++,r--;
	}
	cout<<ans;
}
//9.23£ºT2É¶Ìâ°¡ £¿£¿£¿¼²¿àÁË¡£ 
 
