#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll sum,ans,gg;
struct ddd{
	ll a;
	char c;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		sum+=s[i].a;
	}
	int l=1,r=n;
	while(gg<sum/2){
		if(s[l].a==s[r].a){
			gg+=s[l].a;
			if(s[l].c!=s[r].c)ans+=s[l].a;
			l++;
			r--;
		}
		else if(s[l].a<s[r].a){
			gg+=s[l].a;
			if(s[l].c!=s[r].c)ans+=s[l].a;
			s[r].a-=s[l].a;
			l++;
		}
		else{
			gg+=s[r].a;
			if(s[l].c!=s[r].c)ans+=s[r].a;
			s[l].a-=s[r].a;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
