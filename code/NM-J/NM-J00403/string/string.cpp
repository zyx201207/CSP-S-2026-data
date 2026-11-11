#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,ans,len;
long long a[2*N];
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cin>>c; 
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
} 
