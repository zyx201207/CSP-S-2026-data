#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,len,ans,l,r;
char c;
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		for(int j=1;j<=a;j++) s+=c;
	}
	if(len%2==0){
		l=len/2,r=len/2+1;
		while(l>0||r<len){
			if(s[l]!=s[r]){
				ans++;
//				cout<<l<<' '<<r<<'\n';
			}
			l--,r++;
		}
	}else{
		l=len/2+1,r=len/2+1;
		while(l>0||r<len){
			if(s[l]!=s[r]){
				ans++;
//				cout<<l<<' '<<r<<'\n';
			}
			l--,r++;
		}
	}
	cout<<ans;
	return 0;
}

