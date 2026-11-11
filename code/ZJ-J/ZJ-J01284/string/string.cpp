#include<bits/stdc++.h>
using namespace std;
struct box {
	long long s,e;
	char c;
};
box a[200010];
long long n;
int main() {
	//freopen("E:/down/string/string6.in","r",stdin);
	//freopen("E:/down/string/string.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long tmp=0;
	for(int i=1; i<=n; i++) {
		long long x;
		char c;
		cin>>x>>c;
		a[i]= {tmp+1,tmp+x,c};
		tmp+=x;
	}
	long long l=1,r=tmp,res=0,lid=1,rid=n;
	while(l<r) {
		//cout<<"!!!"<<l<<" "<<r<<" "<<lid<<" "<<rid<<" "<<res<<endl;
		long long l1=0,l2=0;
		l1=a[lid].e-l;
		l2=r-a[rid].s;
		if(l1>l2) {
			if(a[lid].c!=a[rid].c){
				res+=l2+1;
			}
			l+=l2+1;
			r-=l2+1;
		}else{
			if(a[lid].c!=a[rid].c){
				res+=l1+1;
			}
			l+=l1+1;
			r-=l1+1;
		}
		if(l>a[lid].e){
			lid++;
		}
		if(r<a[rid].s){
			rid--;
		}
	}
	cout<<res;
	return 0;
}