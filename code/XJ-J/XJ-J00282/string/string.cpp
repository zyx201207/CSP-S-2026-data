#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef double dou;
typedef unsigned int uint;
typedef unsigned long long ull;
const int N=2e5+5;
ull n,a[N],ans,cnt;
str s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		str k;cin>>k;
		for(ull j=1;j<=a[i];j++)s+=k;
	}
	bool flag=true;
	for(int i=0;i<n-1;i++){
		if(s[i]!=s[i+1]){
			flag=false;
			break;
		}
	}
	if(flag==true){
		cout<<0;
		return 0;
	}
	for(int i=0;i<cnt-i;i++){
		int j=cnt-i;
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
} 
