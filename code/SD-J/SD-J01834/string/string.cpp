#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,len=0,cnt=0;
string str;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		string zf;
		cin>>num>>zf;
		len+=num;
		for(int j=1;j<=num;j++){
			str+=zf;
		}
	}
	for(int i=0;i<=(len/2)-!(len%2);i++){
		if(str[i]!=str[len-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
