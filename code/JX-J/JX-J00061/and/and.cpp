#include<bits/stdc++.h>
using namespace std;
string fx(int x){
	string s="",s1="";
	while(x){
		s+=char(x%2+48);
		x/=2;
	}
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	return s1;
}
bool cmp(string x,string y){
	int x1=0,x2=0;
	int lenx=x.length(),leny=y.length();
	for(int i=0;i<lenx;i++){
		if(x[i]=='1'){
			x1++;
		}
	}
	for(int i=0;i<leny;i++){
		if(y[i]=='1'){
			x2++;
		}
	}
	if(x1!=x2){
		return x1>x2;
	}else{
		return x>y;
	}
}
vector<string>g;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		g.push_back(fx(a[i]));
	}
	sort(g.begin(),g.end(),cmp);
	string ans=g[0];
	for(int i=1;i<m;i++){
		int len1=ans.size(),len2=g[i].size();
		for(int j=min(len1,len2)-1;j>=0;j--){
			if(ans[j]==g[i][j]&&ans[j]=='1'){
				ans[j]='1';
			}else{
				ans[j]='0';
			}
		}
	}
	long long ansd=0,k=0;
	for(int i=ans.size()-1;i>=0;i--){
		if(ans[i]!='0'){
			ansd+=pow(2,k);
		}
		k++;
	}
	cout<<ansd;
}
