#include<bits/stdc++.h>
using namespace std;
char a[500009];
int tong[100];
int zhao(string b,char c){
	for(int i=0;i<b.size();i++){
		if(b[i]==c){
			return i;
		}
	}
	return -1;
}
string sc(string c,int i){
	string b="";
	for(int ii=0;ii<i;ii++){
		b+=c[i];
	} 
	return b;
	
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,mx=0,mn=2147483647;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		string b;
		for(int j=1;j<=n;j++){
			b+=a[i];
			if(zhao(b,a[i])!=-1){
				int aaaa=zhao(b,a[i]);
				b=sc(b,aaaa);
			}
		}
		for(int i=0;i<b.size();i++){
			tong[b[i]-'0']++;
			mx=max(mx,b[i]-'0');
			mn=min(mn,b[i]-'0');
		}
	}
	for(int i=mn;i<=mx;i++){
		if(tong[i]!=0){
			cout<<tong[i]<<" ";
		}
	}
	return 0;
} 
