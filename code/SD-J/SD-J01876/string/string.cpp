#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s="",sx="";
ll n,m,slen=0,k=0,cnt=0;
char a;
bool ishui(string s1){
	string s2=s1;
	reverse(s1.begin(),s1.end());
	return s1==s2;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>m;
		cin>>a;
		slen+=m;
		for(ll j=0;j<m;j++){
			s+=a;
		}
	}
	if(ishui(s)){
		cout<<0;
		return 0;
	}else{
		ll q=0;
		for(ll i=0;i<slen/2;i++){
			sx+=s[i];
		}
		if(slen%2==0){
			k=slen/2;
		}
		else{
			k=slen/2+1;
		}
		for(ll i=slen-1;i>=k;i--){
			if(s[i]!=sx[q]){
				q++;
				
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
} 
