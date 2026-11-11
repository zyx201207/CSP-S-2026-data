#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define ft first
#define sd second
using namespace std;
string c,s,cc,ss;
string ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		ans[0]='1';
	}
	if(c==cc&&s[0]==ss[0]&&s[1]==ss[1]){
		ans[1]='1';
	}
	if((c==cc&&s[0]==ss[0]&&s[1]==ss[1])&&(('D'<=s[2]&&s[2]<='F'&&'D'<=ss[2]&&ss[2]<='F')||('A'<=s[2]&&s[2]<='C'&&'A'<=ss[2]&&ss[2]<='C'))){
		ans[2]='1';
		if(s[2]>ss[2]){
			swap(s[2],ss[2]);
		}
		if(ss[2]-s[2]==1){
			ans[3]='1';
		}
	}
	cout<<ans;
	return 0;
}
