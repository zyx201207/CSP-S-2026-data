#include<bits\stdc++.h>
using namespace std;
int n,m,ma;
int a[200010];
int ans;
int p=1,k=0;
string s[200010];
bool cmp(int x,int y){
	string r="",t="";
	int o=p;
	while(o>0){
		r+=char(x&o+'0');
		t+=char(y&o+'0');
		o/=2;
	}
	for(int i=0;i<=k;i++){
		if(r[i]!=t[i])return r[i]>t[i];
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(a[i],ma);
	}
	while(p<a[1]){
		p*=2;
		k++;
	}
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++)ans=ans&a[i];
	cout<<ans<<endl;
	return 0;
}
