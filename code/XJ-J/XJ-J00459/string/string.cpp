#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],sum=0,ans=0;
char c[N];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	s="";
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		sum+=a[i];
	}long long l=0,r=sum-1;
	while(l<=r){
		if(s[l]!=s[r]){
			ans++;
		}
		l++;
		r--;
	}cout<<ans;
	
	return 0;
}