#include<bits/stdc++.h>
using namespace std;
int a[200002];
char c[200002];
string s;
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	int gy=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
		if(i!=1){
			gy=gcd(gy,a[i]);
		}
		else{
			gy=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		a[i]/=gy;
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	long long ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	ans*=gy;
	cout<<ans;
	return 0;
}
