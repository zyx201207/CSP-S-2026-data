#include<bits/stdc++.h>
using namespace std;
bool cmp(string x,string y){
	int c1=0,c2=0;
	for(int i=0;i<20;i++)if(x[i]==1)c1++;
	for(int i=0;i<20;i++)if(y[i]==1)c2++;
	return c1>c2;
}
string yh(string x,string y){
	for(int i=0;i<20;i++){
		if(x[i]=='1'&&y[i]=='1')x[i]='1';
		else x[i]='0';
	}
	return x;
}
unsigned long long b(string x){
	unsigned long long a=0,g=1;
	for(int i=19,j=0;i>=0;i--,j++)a+=g*(x[i]-48)*pow(2,j);
	return a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<string> a;
	unsigned long long y;
	for(int i=0;i<n;i++){
		cin>>y;
		bitset<20> x(y);
		a.push_back(x.to_string());
	}
	sort(a.begin(),a.end(),cmp);
	string ans=a[0];
	for(int i=1;i<m;i++)ans=yh(ans,a[i]);
	cout<<b(ans)<<'\n';
	return 0;
}
