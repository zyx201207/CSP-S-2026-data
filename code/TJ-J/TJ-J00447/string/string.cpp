#include<iostream>
#include<string>
#include<cstdio>
#define ll long long 
using namespace std; 
string a;
ll n,g;
char c,nc;
bool flag=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>g>>c;
		if(i!=0&&c!=nc){
			flag=1;
		}else if(i==0) nc=c;
		while(g--) a+=c;
	}
	if(flag==0)cout<<"0\n";
	else{
		string aq="",ah="";
		if(a.size()%2==0){
			for(ll i=0;i<a.size()/2;i++){
				aq+=a[i]; 
			}
		}else{
			for(ll i=0;i<=a.size()/2;i++){
				aq+=a[i]; 
			}	
		}
		for(ll i=a.size()-1;i>=a.size()/2;i--){
			ah+=a[i]; 
		}
		
		ll ans=0;
		for(ll i=0;i<a.size()/2;i++){
			if(aq[i]!=ah[i]) ans++;
		}
		cout<<ans<<'\n';
	} 
	return 0;
}
