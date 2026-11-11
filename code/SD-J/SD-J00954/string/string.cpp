#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	string s="";
	while(n--){
		int a;
		char c;
		cin>>a>>c;
		while(a--)
			s+=c;
	} 
	for(int i=0;i<(s.size()-1)/2;i++)
		ans+=(s[i]!=s[s.size()-i-1]);
	cout<<ans;
	return 0;
}
/*

存储问题
单词存储如何达到O(1)

a<=1e9,n<=2e5

存储：O(an) 

预计拿不到点13~16,22~25

68pts 

stk

 
*/
