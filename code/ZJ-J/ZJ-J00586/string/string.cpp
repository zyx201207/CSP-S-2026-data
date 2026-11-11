#include<bits/stdc++.h>
using namespace std;
long long n,t,ans;
char c;
string a="";
bool go=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=2000){
		for(int i=1;i<=n;i++){
			cin>>t>>c;
			if(t>50) go=0;
			if(go) while(t--) a+=c;
		}
		if(!go) return 0;
		if(a.size()==1) cout<<0;
		for(int i=0;i<=(a.size()-2)/2;i++){
			if(a[i]!=a[a.size()-1-i]) ans++;
		}
		cout<<ans;
	}
	return 0;
}