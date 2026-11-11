#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
string s,c,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	t=s;
	long long l=0,r=t.size()-1;
	for(long long i=0;i<t.size();i++){
		swap(t[l],t[r]);
		l++;
		r--;
		if(l==r){
			break;
		}
	}
	for(long long i=0;i<=t.size();i++){
		if(s[i]!=t[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
