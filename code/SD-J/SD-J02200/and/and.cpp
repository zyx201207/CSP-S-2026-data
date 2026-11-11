#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200005],tp[35];
map<int,int>mp;
string s[200005];
string ten_to_two(int x){
	string num;
	while (x) num+=x%2+'0',x/=2 ;
	reverse(num.begin(),num.end());
	return num;
}
LL two_to_ten(string str){
	LL num=0;
	for (int i=str.size()-1;i>=0;i--){
		num+=(str[i]-'0')*tp[str.size()-i-1];
		tp[str.size()-i]=tp[str.size()-i-1]*2ll;
	}
	return num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	tp[0]=1;
	int n,m;cin>>n>>m;
	int maxx_size=-1;
	for (int i=1;i<=n;i++){
		mp[i]=i;
		cin>>a[i];
		s[i]=ten_to_two(a[i]);
		maxx_size=max((int)s[i].size(),maxx_size);
	}
	for (int i=1;i<=n;i++){
		while ((int)s[i].size()<maxx_size) s[i]='0'+s[i];
	}
	string ans;
	for (int i=0;i<maxx_size;i++){
		int cot=0;
		for (auto it:mp){
			int j=it.first,x=it.second;
			if (x==0) continue;
			if (s[j][i]=='1') cot++;
		}
		if (cot<m) ans+='0';
		else if (cot==m){
			int x[m],id=0;
			for (auto it:mp){
				int j=it.first,xx=it.second;
				if (xx==0) continue;
				if (s[j][i]=='1') x[id++]=j;
			}
			LL and_sum=a[x[0]];
			for (int j=0;j<m;j++) and_sum=and_sum&a[x[j]];
			cout<<and_sum;
			return 0;
		}else{
			ans+='1';
			for (auto it:mp){
				int j=it.first,x=it.second;
				if (x==0) continue;
				if (s[j][i]!='1') mp[j]=0;
			}
		}
	}
	cout<<two_to_ten(ans);
	return 0;
}
