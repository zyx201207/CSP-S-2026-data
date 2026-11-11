#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200100];
int b=-1;
string s[200100];
int d=-1;
string er(int a){
	if(a==1){
		return "1";
	}
	if(a==2){
		return "10";
	}
	if(a==3){
		return "11";
	}
	string s="";
	while(1){
		int b=a%2;
		if(b==0){
			s='0'+s;
		}else{
			s='1'+s;
		}
		a=a/2;
		if(a==1){
			s='1'+s;
			break;
		}
	}
	return s;
}
int yu(string a,string b){
	int c=0;
	string s="";
	if(a.size()>b.size()){
		for(int i=b.size()-1;i>=0;i--){
			if(b[i]=='1'&&a[a.size()-b.size()+i]=='1'){
				s='1'+s;
			}else{
				s='0'+s;
			}
		}
	}else{
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='1'&&b[b.size()-a.size()+i]=='1'){
				s='1'+s;
			}else{
				s='0'+s;
			}
		}
	}
	int n=1;
	for(int i=s.size()-1;i>=0;i--){
		c=c+(s[i]-'0')*n;
		n=n*2;
	}
	return c;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b=max(a[i],b);
		s[i]=er(a[i]);
	}
	if(m==1){
		cout<<b;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				d=max(d,yu(s[i],s[j]));
			}
		}
		cout<<d;
		return 0;
	}
	if(m==3){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					d=max(d,yu(er(yu(s[i],s[j])),s[k]));
				}
			}
		}
		cout<<d;
		return 0;
	}
	if(m==4){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					d=max(d,yu(er(yu(s[i],s[j])),s[k]));
				}
			}
		}
		cout<<d;
		return 0;
	}else{
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				d=max(d,yu(s[i],s[j]));
			}
		}
		cout<<d;
		return 0;
	}
	cout<<a[n];
	return 0;
}
