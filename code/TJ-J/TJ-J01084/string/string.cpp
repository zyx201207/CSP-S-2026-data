#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
typedef long long ll;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		string y;
		cin>>y;
		for(int j=1;j<=x;j++){
		    a+=y;	
		}
	}
	ll ans=0;
	ll x=0,y=a.size()-1;
	//cout<<a<<endl;
	for(ll i=6;i>=1;i++){
		if(x==y){
			//cout<<"x=y";
			break;
		}
		if(a[x]!=a[y]){
		    ans+=1;	
		    //cout<<"ans="<<ans;
		}
		if(x==y-1){
			//cout<<"x==y-1";
			break;
		}
		x+=1;
		y-=1;
		//cout<<"x:y="<<x<<" "<<y;
		//cout<<endl;
		
	}
	cout<<ans;
	
    
	return 0;
} 
