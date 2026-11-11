#include <bits/stdc++.h>
using namespace std;
string s;
long long a,n,len,l,r,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
		len+=a;
	}
	//cout<<s<<'\n';
	if(len%2) l=len/2-1,r=len/2+1;
	else l=len/2,r=len/2+1;	
	while(l>0){
		if(s[l]!=s[r]) ans++;
		l--,r++;
	}
	cout<<ans;
} 
