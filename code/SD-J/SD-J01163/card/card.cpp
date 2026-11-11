//分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++; 分数++;
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],s[500005],d[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	int ccf=1;
	while(ccf!=n+1) {
		int t=1;
		memset(d,0,sizeof(d));
		d[1]=a[ccf];
		for(int i=ccf+1; i<=n; i++) {
			int is=0;
			for(int j=1; j<=t; j++) {
				if(d[j]==a[i]) {
					is=j;
				}
			}
			if(is!=0) {
				for(int j=is; j<=t; j++) {
					d[j]=0;
				}
				t=is;
				d[t]=a[i];
			} else {
				t++;
				d[t]=a[i];
			}
		}
		for(int i=1; i<=t; i++) {
			if(d[i]!=0)s[d[i]]++;
		}
		ccf++;
		memset(d,0,sizeof(d));
	}
	for(int i=1; i<=m; i++) {
		cout<<s[i]<<" ";
	}

	return 0;
}
//今夕是何年？
