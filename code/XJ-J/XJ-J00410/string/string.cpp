#include<bits/stdc++.h>
using namespace std;
#define long long 
const int N=2e5+10;
long long int n,a,len=0,cnt=0;
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(),cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s1;
		len+=a;
		for(int j=1;j<=a;j++){
			s=s+s1;
		}
	}
	long long int l=0,r=len-1;
	for(int i=0;i<len-1;i++){
		if(l==r){
			break;
		}
		if(s[l]!=s[r]){
			cnt++;
			l++,r--;
		}
	}
	cout<<cnt;
}