#include<bits/stdc++.h>
using namespace std;
int n,m,ma,b[200005],o;
struct stu{
	int r;
	string s;
}a[200005];
string f(int d){
	if(d!=0) return f(d/2)+char(d%2+'0');
	else return "0";
}
bool cmp(stu x,stu y){
	return x.s>y.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].r;
		a[i].s=f(a[i].r);
		string ss=a[i].s;
		int c=ss.size();
		ma=max(ma,c);
		if(c<32){
			for(;c<32;c++){
				a[i].s="0"+a[i].s;
			}
		}
	}
	sort(a,a+n,cmp);
	for(int j=0;j<n;j++){
		if(a[j].s[33-ma]=='1') b[o++]=j;
	}
	if(o>=m){
		int k=2147483647;
		for(int j=0;j<m;j++){
			k&=a[b[j]].r;
		}
		cout<<k;
	}else{
		int k;
		int e[200005];
		bool f=1;
		for(int i=35-ma;i<=32;i++){
			k=0;
			for(int j=0;j<200005;j++) e[j]=0;
			for(int j=0;j<n;j++){
				if(a[j].s[i]=='1'){
					e[k++]=j;
				}
			}
			if(k>=m){
				f=0;
				int l=2147483647;
				for(int j=0;j<m;j++){
					l&=a[e[j]].r;
				}
				cout<<l;
				return 0;
			}
		}
		if(f) cout<<0;
	}
	return 0;
}
