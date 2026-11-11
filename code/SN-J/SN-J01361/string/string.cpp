#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s1="";
	ll sum=0;
	ll maxx=-1;
	for(int i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		sum+=a;
		maxx=max(maxx,a);
		for(int j=1;j<=a;j++){
			s1.push_back(c);
		}
	}
	string r_s=s1;
	reverse(s1.begin(),s1.end());
	if(s1==r_s){
		cout<<0<<'\n';
	}
	else if(s1.size()%2!=0){
		cout<<sum/2<<'\n';
	}
	else{
		cout<<sum-maxx<<'\n';
	}
	return 0;
}
