#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,k,ans;
ll a[5];
void solve(){
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<"1";
	else cout<<"0";
	ll tmp1=(s2[0]-'0')*10+(s2[1]-'0');
	ll tmp2=(s4[0]-'0')*10+(s4[1]-'0');
	if(tmp1==tmp2&&s1==s3) cout<<"1";
	else cout<<"0";
	if((s2[2]=='A')||(s2[2]=='B')||(s2[2]=='C')) ++a[1];
	if((s4[2]=='A')||(s4[2]=='B')||(s4[2]=='C')) ++a[1];
	if((s2[2]=='D')||(s2[2]=='E')) ++a[2];
	if((s4[2]=='D')||(s4[2]=='E')) ++a[2];
	if((tmp1==tmp2)&&(!(a[1]!=0&&a[2]!=0))&&s1==s3&&tmp1==tmp2) cout<<"1";
	else cout<<"0";
	char v1=s2[2],v2=s4[2];
	if(v1>v2) swap(v1,v2);
	ll tmp3=(v1=='A'&&v2=='B')||(v1=='B'&&v2=='C')||(v1=='D'&&v2=='E');
	if(tmp3&&tmp1==tmp2&&s1==s3) cout<<"1";
	else cout<<"0";
	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	solve();
	return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
02 02B 02 01A
02 01A 03 01A
*/
