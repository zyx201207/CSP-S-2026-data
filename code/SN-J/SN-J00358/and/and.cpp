#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxx,b;
int p(int x){
	int cnt=0;
	for(int i=1073741824;i>=1;i>>=1){
		if(x>=i)x-=i,cnt++;
		if(x==0)break;
	}
	return cnt;
}
int q(int x){
	int y=b,cnt=0;
	for(int i=1073741824;i>=1;i>>=1){
		if(y/i!=x/i)cnt++;
		else if(y/i==1)y-=i,x-=i;
	}
	return cnt;
}
bool cmp(int x,int y){
	if(q(x)==q(y))return x>y;
	return q(x)<q(y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(p(a[i])>maxx)maxx=p(a[i]),b=a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++)ans&=a[i];
	cout<<ans;
}
//gugugaga gugugaga gugugaga!!!
