#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
long long a[200005];
string s[200005];
string zys(int x){
	string ss;
	while(x>0){
		ss+=char(x%2+48);
		x/=2;
	}
	string sss="";
	for(int i=ss.size()-1;i>=0;i--)sss+=ss[i];
	return sss;
}
int zsy(string s){
	int x=0;
	for(int i=0;i<s.size();i++){
		int lc=int(s[i])-48;
		for(int j=0;j<s.size()-i-1;j++){
			lc*=2;
		}
		x+=lc;
	}
	return x;
}
string yjx(string ss,string tt){
	string cnt;
	if(ss.size()>tt.size()){
		for(int i=0;i<tt.size();i++){
			if(ss[i+ss.size()-tt.size()]==tt[i]&&tt[i]=='1')cnt+='1';
			else cnt+='0';
		}
	}
	else{
		for(int i=0;i<ss.size();i++){
			if(tt[i+tt.size()-ss.size()]==ss[i]&&ss[i]=='1')cnt+='1';
			else cnt+='0';
		}
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flg=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s[i]=zys(a[i]);
		if(a[i]!=i)flg=false;
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
		return 0;
	} 
	if(m==2){
		int m_s=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				string st=yjx(s[i],s[j]);
				m_s=max(zsy(st),m_s);
			}
		}
		cout<<m_s;
		return 0;
	}
	if(m==n){
		int myx=0;
		string zg=s[0];
		for(int i=0;i<n;i++){
			zg=yjx(zg,s[i]);
		}
		cout<<zsy(zg);
		return 0;
	}
	sort(a,a+n);
	cout<<a[n-m];
	return 0;
}

