#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct st{
	ll a;
	char b;
}c[200005];
ll ans,mod;
char l;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>c[i].a>>c[i].b;
	/*for(int i=1;i<=n/2+1;i++){
		int j=n-i+1;
		if(c[i].b!=c[j].b)ans+=min(c[i].a,c[j].a);
		else{
			if(c[i].a>=c[j].a)c[i].a-=c[j].a;
			else c[j].a-=c[i].a;
		}
		mod=abs(c[i].a-c[j].a);
		if(mod==0)continue;
		if(c[i].a>=c[j].a)l=c[i].a;
		else l=c[j].b;
		for(int x=j-1;x>i;x--){
			if(l==c[x].b){
				if(mod<=c[x].a)c[x].a-=mod,mod=0;
				else mod-=c[x].a,c[x].a=0;
			}
			else{
				if(mod<=c[x].a)c[x].a-=mod,ans+=mod,mod=0;
				else mod-=c[x].a,c[x].a=0;
			}
			if(mod==0)break;
		}
	}
	cout<<ans;*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c[i].a;j++){
			s+=c[i].b;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])ans++;
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!

