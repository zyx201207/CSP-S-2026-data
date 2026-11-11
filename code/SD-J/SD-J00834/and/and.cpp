#include <bits/stdc++.h>
using namespace std;
struct _bit{
	string s;
	long long noo;
};
string _itot(long long a)
{
	string s;
	while(a){
		s+=a%2+'0';
		a/=2; 
	}
	while(s.size()<20)
	{
		s+='0';
	}
	reverse(s.begin(),s.end());
	return s; 
}
long long _noo(string s)
{
	long long cnt=0;
	for(char c:s)
	{
		if(c=='1') cnt++;
	}
	return cnt;
}
_bit _itob(long long a)
{
	string s = _itot(a);
	return {s,_noo(s)};
}
string _band(string s1,string s2)
{
	string s;
	long long l = max(s1.size(),s2.size());
	for(long long i=0;i<l;i++){
		if(s1[i]=='1'&&s2[i]=='1')
			s+='1';
		else 
			s+='0';
	}
	return s;
}
long long _stoi(string s)
{
	long long ans=0;
	reverse(s.begin(),s.end());
	long long l = s.size();
	for(long long i=0;i<l;i++)
	{
		if(s[i]=='1'){
			ans+=pow(2,i);
		}
	}
	return ans;
}
bool cmp(_bit a,_bit b){
	long long ao=0,bo=0;
	for(long long i=0;i<a.s.size();i++) if(a.s[i]=='1'){ao=i;break;}
	for(long long i=0;i<b.s.size();i++) if(b.s[i]=='1'){bo=i;break;}
	if(a.noo == b.noo){
		return ao<bo;
	}
	return a.noo>b.noo;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	vector<_bit> a(n);
	for(long long i=0;i<n;i++)
	{
		long long t=0;
		cin >> t;
		a[i]=_itob(t);
	} 
//	for(long long i=0;i<n;i++)
//	{
//		cout << a[i].s << a[i].noo << endl;
//	}
//	cout << "----------------------------------------------";
	sort(a.begin(),a.end(),cmp);
//	for(long long i=0;i<n;i++)
//	{
//		cout << a[i].s << a[i].noo << endl;
//	}
	string ans="11111111111111111111";
//	cout << "----------------------------------------------";
	for(long long i=0;i<m;i++)
	{
//		cout << "将要传入" << ans << "与" << a[i].s << endl;; 
		ans = _band(ans,a[i].s);
	}
	cout << _stoi(ans);
 } 
