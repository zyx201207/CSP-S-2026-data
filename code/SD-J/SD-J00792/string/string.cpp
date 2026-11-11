#include<bits/stdc++.h>
#define int long long
#define uint unsigned long long
#define fst ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
using namespace std;
const int N=1e6+5;
int n,sum;
uint a,len;
char c;
string s=" ";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fst;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		while(a--){
			s+=c;
		}
	}
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
