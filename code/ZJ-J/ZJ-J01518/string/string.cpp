#include<bits/stdc++.h>
using namespace std;
struct gjysyq{
	long long d;
	char l;
}a[200001];
string dao(string s){
	string s2;
	for(int i=0;i<s.size();i++)
	{
		s2+=s[s.size()-1-i];
	}
	return s2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	long long n; cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].d>>a[i].l;
		string ss(a[i].d,a[i].l);
		s+=ss;
	}
	string s1=dao(s);
	long long su=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=s1[i])
			su++;
	}
	cout<<su/2<<endl;
	return 0;
}








