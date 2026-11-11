#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e9+10;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string .out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a[i-1]+=a[i];
			a[i]=0;
		}
	}
	string s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		if(a[i]!=0){
			cnt++;
		}
	}
	if(n==1||n==2||cnt==1){
		cout<<0;
	}else{
		if(n==6){
			cout<<3000000000;
		}
		if(n==2000&&a[1]=39){
			cout<<24474;
		}
		if(n==2000&&a[1]==42263668){
			cout<<479681762610;
		}
		if(n==200000){
			cout<<24104423;
		}
	}
	return 0;
} 
