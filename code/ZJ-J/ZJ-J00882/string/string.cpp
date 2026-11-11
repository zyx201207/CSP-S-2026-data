#include<bits/stdc++.h>
using namespace std;

long long int ans,cnt,n,a[200010];
char s[200010][110];
string s0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
		string s;
		cin>>s;
		for(int j=1;j<=a[i];j++){
			s0+=s;
		}
	}
	for(int i=0;i<ans/2;i++){
		if(s0[i]!=s0[ans-i-1])  cnt++;
	}
	cout << cnt;
	
	return 0;
}