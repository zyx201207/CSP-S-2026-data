#include<bits/stdc++.h>
using namespace std;
struct num{
	int ten;
	int two;
}a[200005];
bool cmp(num x,num y){
	if(x.two!=y.two) return x.two>y.two;
	return x.ten>y.ten;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].ten;
		string s="";
		int x=a[i].ten;
		while(x>0){
			s+=x%2+'0';
			x/=2;
		} 
		for(int j=0;j<s.size();j++){
			if(s[j]=='1') a[i].two++;
		}
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1].ten;
	for(int i=2;i<=m;i++){
		ans&=a[i].ten;
	}
	cout<<ans;
	return 0;
}
