#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200010],ans;
char ch[200010];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		ans+=a[i];
	}
	if(ans<=10000000){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=a[i];j++) s+=ch[i];
		ll cnt=0;
		for(int i=0;i<ans;i++) if(s[i]!=s[ans-i-1]) cnt++;
		cout<<cnt/2;
		return 0;
	}
	cout<<ans/2;
	return 0;
}
