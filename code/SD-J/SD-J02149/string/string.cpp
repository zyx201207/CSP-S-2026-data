#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,len,cnt;
char cha;
string str=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x>>cha;
		for(int i=len;i<=len+x;i++){
			s+=cha;
		}
		len+=x;
	}
	for(int i=1;i<=len;i++){
		if(s[i]!=s[len-i+1])++cnt;
	}
	cout<<cnt;
	return 0;
}
//RP+=INF
