#include<bits/stdc++.h>
using namespace std;
long long n,len,l,r,g=1,t2;
string s,s2,t;
vector<long long> a;
vector<string> c;
int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t2;
		a.push_back(t2);
		cin>>t;
		c.push_back(t);
	}
	g=gcd(a[0],a[1]);
	for(int i=2;i<n;i++){
		g=gcd(g,a[i]);
	}
	for(int i=0;i<n;i++){
		a[i]=a[i]/g;
		len+=a[i];
		while(a[i]--){
			s+=c[i];
		}
	}
	if(len%2==1) len--;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i]) l++;	
	}
	cout<<l*g;
	return 0;
}


