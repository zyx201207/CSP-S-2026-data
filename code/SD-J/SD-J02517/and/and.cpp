#include<bits/stdc++.h>
using namespace std;
string jinzhi(long long a){
	long long n=1;
	int b=1;
	string s="00000000000000000000000000000000000000000";
	while(a>n){
		n*=2;
		b+=1;
	}
	for(int i=n;i>=1;i=i/2){
		if(a-i>=0){
			s[b]='1';
			a-=i;
		}else{
			s[b]='0';
		}
		b-=1;
	}	
	return s;
}
bool cnr(long long a,long long b){
	if(a<b){
		return false;
	}else{
		return true;
	}
}
long long max(long long a[20000],int n,int m){
	sort(a+1,a+1+n,cnr);
	return a[m];
}
long long s[20000];
long long d[20000];
int main(){
	int n,m;
	long long a;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i+=1){
		cin>>s[i];
	}
	long long cs;
	for(int i=1;i<=m;i+=1){
		d[i]=max(s,n,i);
		cs=i;
	}cout<<d[cs];
	return 0;
}
