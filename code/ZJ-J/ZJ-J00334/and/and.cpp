#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],cnt[35];
string c10to2(int x){
	string s1;
	while(x!=0){
		if(x%2)s1=s1+'1';
		else s1=s1+'0';
		x/=2;
	}
	string s="";
	int len=s1.size();
	for(int i=0;i<len;i++){
		s=s+s1[len-1-i];
	}
	while(s.size()!=30){
		s='0'+s;
	}
	return s;
}
int qpow(int x,int y){
	int ans;
	ans=1;
	for(int i=1;i<=y;i++){
		ans*=x;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		string s=c10to2(a[i]);
		for(int i=0;i<30;i++){
			cnt[i]+=s[i]-48;
		}
	}
	sort(a+1,a+1+n);
	for(int i=0;i<30;i++){
		if(cnt[i]>=m){
			int res=pow(2,31)-1;
			for(int j=n;j>n-m;j--){
				res&=a[j];
			}
			cout<<res;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
