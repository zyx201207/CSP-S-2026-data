#include<bits/stdc++.h>
using namespace std;
long long int n,a,cnt,ans,anss;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--){
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
		cnt+=a;
	}
	string ss=s;
	long long l=ceil(cnt/2),r=ss.size()-1;
	for(int i=0;i<=l-1;i++)
		if(ss[i]!=ss[cnt-1-i])
			ss[i]=ss[cnt-1-i],ans++;
	for(int i=l;i<=s.size()-1;i++)
		if(s[i]!=s[cnt-1-i])
			s[i]=s[cnt-1-i],anss++;
	cout<<max(ans,anss);
	return 0;
}
