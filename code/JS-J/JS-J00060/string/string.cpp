#include <bits/stdc++.h>
using namespace std;
const int N=1e8+10;
long long n;
long long t;
string c;
string s;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--){
		cin>>t>>c;
		while(t--){
			s+=c;
		}
	}
	long long len=s.size();
	if(len%2==1){
		long long i=len/2,j=len/2;
		while(i>=0&&j<len){
			if(s[i]!=s[j]){
				ans++;
			}
			i--,j++;
		}
	}
	else{
		long long i=len/2-1,j=len/2;
		while(i>=0&&j<len){
			if(s[i]!=s[j]){
				ans++;
			}
			i--,j++;
		}
	}
	cout<<ans;
	return 0;
}
