#include<bits/stdc++.h>
using namespace std;
const int mxn=2e5+5;
int n,m,a[mxn],c[30],d[30],ans,mx;
struct stu{
	int a,s[30];
}b[mxn];
bool cmp(stu x,stu y){
	return x.a>y.a;
}
int main(){
	//Trick||Treat!
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];b[i].a=a[i];}
	for(int i=1;i<=n;i++){
		int j=0;
		while(a[i]){
			b[i].s[++j]=a[i]&1;
			c[j]+=a[i]&1;
			a[i]/=2;
		}
	}
	for(int i=1;i<=30;i++){
		if(c[i]>=m) mx=i;
	}
	for(int i=1;i<=n;i++) b[i].a%=1<<mx;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=mx;j++){
			d[j]+=b[i].s[j];
		}
	}
	for(int i=mx;i>=1;i--){
		ans=ans*2;
		if(d[i]>=m) ans++;
	}
	cout<<ans;
	return 0;
}
