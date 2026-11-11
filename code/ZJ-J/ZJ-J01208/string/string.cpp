#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const long long INF=0x3f3f3f3f3f3f3f3f;
long long maxs;
long long l[N];
long long p[N];
char c[N];
int n,m; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		long long s;
		char r;
		cin>>s>>r;
		maxs+=s;
		if (r!=c[m]){
			m++;
			p[m]=p[m-1];
			p[m]+=s;
			c[m]=r;
			l[m]=s;
		}
		else {

			p[m]+=s;
			l[m]+=s;
		}
	}
	long long nowllen=1,nowrlen=maxs;
	long long nowl=1,nowr=m;
	long long sum=0;
	while (nowl<nowr && nowllen<nowrlen){
		long long minn=INF;
		minn=min(minn,min(p[nowl]-nowllen+1,nowrlen-p[nowr-1]));
		if (c[nowl]!=c[nowr]){
			sum+=minn;
			nowllen+=minn;
			nowrlen-=minn;
			if (p[nowr-1]==nowrlen)nowr--;
			if (p[nowl]<nowllen)nowl++;
		}
		else {
			nowllen+=minn;
			nowrlen-=minn;
			if (p[nowr-1]==nowrlen)nowr--;
			if (p[nowl]<nowllen)nowl++;		
		}
	}
	cout<<sum<<endl;
	return 0;
}
