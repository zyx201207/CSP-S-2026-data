#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt[30],flag,len;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	s+='0';
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		cnt[c[i]-'a'+1]+=a[i];
		for(int j=1;j<=a[i];j++) s+=c[i];
	}
	for(long long i=1;i<len;i++){
		if(s[i]!=s[len-i+1]) flag=0;
	}
	if(flag){
		cout<<0;
		return 0;
	} 
	else{
		long long mx=INT_MIN;
		for(int i=1;i<=26;i++){
			long long xx=mx;
			mx=max(cnt[i],mx);
		}
		cout<<mx;
	}
	return 0;
}
//weimanfenjieguo
