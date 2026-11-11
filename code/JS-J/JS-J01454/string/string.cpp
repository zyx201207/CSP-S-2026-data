#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-'){f=-1;}
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    n=read();
    string ans;
    for(int i=1;i<=n;i++){
		ll x;
		x=read();
		string c;
		cin>>c;
		for(ll j=1;j<=x;j++){
			ans+=c;
		}
	}
	ans=(" "+ans);
	ll len=(ans.length()-1)/2;
	ll cnt=0;
	for(int i=1;i<=len;i++){
		if(ans[i]!=ans[ans.length()-i]){
			cnt++;
		}
	}
	cout<<cnt;
    return 0;
}
