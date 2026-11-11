//RP+=INF
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
struct awa{
	ll start,end;
	char c;
}s[200005];
ll mid,len,nowl=1,nowr;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;nowr=n;
	s[0].end=0;
	for(int i=1;i<=n;i++){
		int a;char cc;cin>>a>>cc;
		s[i].start=s[i-1].end+1;
		s[i].end=s[i].start+a-1;
		s[i].c=cc;
		len+=a;
	}
	mid=(len+1)>>1;
	for(ll i=1;i<mid;){
		ll j=len+1-i;
		if(i==j)break;
//		cout<<i<<' '<<j<<' '<<nowl<<' '<<nowr<<' '<<ans<<endl;
		if(i>s[nowl].end){nowl++;}
		if(j<s[nowr].start){nowr--;}
		if(s[nowl].c!=s[nowr].c){
//			cout<<114514<<endl;
			ll bian=min(s[nowl].end-i+1,j-s[nowr].start+1);
			ans+=bian;
			i+=bian;
		}
		else if(s[nowl].c==s[nowr].c){
//			cout<<1919810<<endl;
			ll bian=min(s[nowl].end-i+1,j-s[nowr].start+1);
			i+=bian;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/