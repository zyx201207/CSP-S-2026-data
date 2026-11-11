#include<bits/stdc++.h>
using namespace std;
struct qwq{
	long long a;
	string s;
}a[200001];
int cmp(qwq q,qwq w){
	return q.s>w.s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		long long aa=a[i].a;
		while(aa){
			if(aa&1)a[i].s='1'+a[i].s;
			else a[i].s='0'+a[i].s;
			aa>>=1;
		}
	}
	sort(a+1,a+1+n,cmp);
	
//	for(int i=1;i<=n;i++){
//		cout<<a[i].a<<" "<<a[i].s<<endl;
//	}
//	cout<<endl;
	long long ans=a[1].a;
	for(int i=2;i<=m;i++){
		ans=ans&a[i].a;
	}
	cout<<ans;
	return 0;
}