#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],sum;
string s,b,ans,c;
bool cmp(int x,int y){
	return x>y;
}
void ejz(int n){
	while (n){
		s+=n%2+'0';
		n/=2;
	}
}
void y(){
	int cd=min(s.size(),ans.size());
	for (int i=cd-1;i>0;i++){
		if (s[i]=='1' && ans[i]=='1'){
			b+='1';
		}else b+='0';
	}
}
void zh(){
	int j=0;
	for (int i=0;i<ans.size();i++){
		sum+=ans[i]*pow(2,j);
		j++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ejz(a[1]);
	for (int i=s.size()-1;i>=0;i++){
		ans+=s[i];
	}
	for (int i=2;i<=m;i++){
		s="";
		b="";
		c="";
		ejz(a[i]);
		for (int j=s.size()-1;j>=0;j++){
		    c+=s[j];
	    }
	    s=c;
		y();
		ans="";
		for (int k=b.size()-1;k>=0;k--){
			ans+=b[k];
		}
		zh();
	}
	cout<<sum;
	return 0;
}