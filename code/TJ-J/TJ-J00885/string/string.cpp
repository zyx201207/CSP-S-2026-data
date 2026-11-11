//666’‚…∂“ı£¨À„¡À∆≠µ„∑‡∞… 
#include<iostream> 
#define ll long long
using namespace std;
string s="";
ll n,m,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll p;
		cin>>p;
		m+=p;
		char aa;
		cin>>aa;
		while(p--){
			s+=aa;
		}
	}
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}

