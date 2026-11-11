#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	ll n,m,a[N]={},p=0,s=0;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		p+=a[i];
	}
	p=(p+m)/n;
	for(ll i=0;i<n;i++){
		if(a[i]>p){
			cout<<s;
			return 0;
		}else{
			s+=1;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
