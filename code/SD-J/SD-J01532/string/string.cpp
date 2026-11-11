#include<bits/stdc++.h>
using namespace std;
int n;//a[2000010]
//long long sum;
//char c[2000010];
string s,s1[200010];
long long a[200010],cnt;
long long sum[200010];
bool f;
int main(){
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s1[i];
	}
	for(int i=1;i<=n;i++){
		while(a[i]--) s+=s1[i];
	}
	int b=(s.size()-1);
	int l=ceil(b/2);
	for(int i=0;i<=l-1;i++){
		if(s[i]!=s[b-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}

