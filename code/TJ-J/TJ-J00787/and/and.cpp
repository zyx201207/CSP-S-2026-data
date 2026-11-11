#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string what_the_hell(long long b){
	long long k=1;
	string ans="";
	while(2*k<b)
		k*=2;
	while(k>0){
		char c='0';
		if(k<=b){
			b-=k;
			c='1';
		}
		ans+=c;
		k/=2;
	}
	return ans;
}

long long holy_shit(string a,string b){
	string c="";
	long long lens=max(a.size(),b.size());
	if(a.size()<b.size()){
		string cnt=a;
		a=b;
		b=cnt;
	}
	reverse(b.begin(),b.end());
	while(a.size()>b.size()){
		b+='0';
	}
	reverse(b.begin(),b.end());
	for(long long i=0;i<lens;i++){
		char cc='0';
		if(a[i]=='1'&&b[i]=='1'){
			cc='1';
		}
		c+=cc;
	}
	long long ans=0,k=1;
	for(int i=0;i<c.size();i++){
		ans+=((c[c.size()-i-1]-'0')*k);
		k*=2;
	}
	return ans;
}

int main(){
	//孤注一掷了，能拿35分就足够了 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	long long maimai[n+5]={0};
	for(int i=1;i<=n;i++){
		cin>>maimai[i];
	}
	long long maxxx=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			if(maimai[i]>maxxx){
				maxxx=maimai[i];
			}
		}
	}
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				string o=what_the_hell(maimai[i]),p=what_the_hell(maimai[j]);
				maxxx=max(maxxx,holy_shit(o,p));
			}
		}
	}
	else if(m==n){
		string DX=what_the_hell(maimai[1]);
		for(int i=2;i<=n;i++){
			maxxx=holy_shit(DX,what_the_hell(maimai[i]));
		}
	}
	cout<<maxxx;
	return 0;
}
