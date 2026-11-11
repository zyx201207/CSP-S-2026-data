#include<bits/stdc++.h>
using namespace std;
#define _ long long
_ a,b,c[500001],qzh[500001],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b;
	for(_ i=1;i<=a;i++){
		cin>>c[i];
	}
	sort(c+1,c+a+1);
	_ l=1;
	for(_ i=1;i<=a;i++){
		qzh[i]=qzh[i-1]+c[i];
		while(c[i]*(i-l+1)-(qzh[i]-qzh[l-1])>b)++l;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}