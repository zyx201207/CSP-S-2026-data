#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
//#define int long long
string s;
int len=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int m;
	char c;
	for(int i=1;i<=n;i++){
		cin>>m;cin>>c;
		cout<<len<<endl;
		for(int j=len;j<len+m;j++) s+=c;
		len+=m;
	}
	int cnt=0;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

