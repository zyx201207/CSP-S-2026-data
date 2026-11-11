#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],w[200001];
string s[200001],t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)	cin>>a[i];
	if(m==1){
		int ma=0;
		for(int i=0;i<n;i++)	if(a[i]>ma)	ma=a[i];
		cout<<ma;
		return 0;
	}
	if(m==n){
		for(int i=0;i<n;i++)
			while(a[i]){
				s[i]+=(a[i]%2+'0');
				a[i]/=2;}
		int mi=100000000;
		for(int i=0;i<n;i++)	if(s[i].size()<mi)	mi=s[i].size();
		for(int i=0;i<mi;i++){
			int y=0;
			for(int j=0;j<n;j++){
				if(s[j][i]=='0'){
					t+='0';
					y=1;
					break;
				}
			}
			if(y==0)	t+='1';
		}
		int r=0;
		for(int i=0;i<t.size();i++)	r+=(t[i]-'0')*((int)pow(2,i));
		cout<<r;
		return 0;
	}
	if(m==n-1){
		for(int o=0;o<n;o++){
			for(int i=0;i<n;i++){
				while(a[i]){
					s[i]+=(a[i]%2+'0');
					a[i]/=2;}
			}
			int mi=100000000;
			for(int i=0;i<n;i++)	if(s[i].size()<mi && i!=o)	mi=s[i].size();
			t="";
			for(int i=0;i<mi;i++){
				int y=0;
				for(int j=0;j<n;j++){
					if(s[j][i]=='0'){
						t+='0';
						y=1;
						break;
					}
				}
				if(y==0)	t+='1';
			}
			for(int i=0;i<t.size();i++)	w[o]+=(t[i]-'0')*((int)pow(2,i));
		}
		int y=0;
		for(int i=0;i<n;i++)	if(y<w[i])	y=w[i];
		cout<<y;
		return 0;
	}
	cout<<0;
	return 0;
}
