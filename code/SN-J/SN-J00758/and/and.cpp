//考号：SN-J00758 姓名：张洛菡 学校：西安市第八中学
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int bin[200005][32];
bool ok[200005];
struct Info {
	int id,value;
} p[200001];
bool cmp(const Info x,const Info y) {
	return x.value>y.value;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i<=n; i++) {
		cin>>a[i];
		p[i].id=i;
		int b=0;
		int x = a[i];
		while(x>0) {
			bin[i][b]=x%2;
			b++;
			x/=2;
		}
	}
	static int v[32];
	int l=0;
	for(int b=30; b>=0; b--) {
		int x=0;
		for(int i = 1; i<=n; i++) {
			if(bin[i][b])x++;
		}
		if(x>=m) {
			v[++l]=b;
		}
	}
	for(int i=1; i<=l; i++) {
		for(int j=1; j<=n; j++) {
			if(bin[j][v[i]]) {
				p[j].value+=pow(2,v[i]+1);
			}

		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int b=30;b>=0;b--)cout<<bin[i][b];
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++){
//		cout<<p[i].id<<' '<<p[i].value<<endl;
//	}
//	for(int i=1;i<=l;i++)cout<<v[i]<<endl;
	sort(p+1,p+n+1,cmp);
	long long ans=a[p[1].id];
	for(int i = 1; i<=m; i++) {
		ans&=a[p[i].id];
		//	cout<<ok[i]<<' ';
	}
//	cout<<endl;
	cout<<ans;
}
//预估得分 100pts
//谁敢信我先开T3
//关注luogu Paranoia_TLE 谢谢啦
