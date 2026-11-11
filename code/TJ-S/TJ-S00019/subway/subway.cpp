#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500011],time1;
struct node{
	long long k;
	long long a[500011],t[500011];
}s[501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>s[i].k;
		for (int j=1;j<=s[i].k;j++){
			cin>>s[i].a[j]>>s[i].t[j];
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		time1=time1+w[x]+w[y];
		int f=0,i1,j1,i2,j2;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=s[i].k;j++){
				if (s[i].a[j]==y){
					i1=i;
					j1=j;
					break;
				}
				if (s[i].a[j]==x){
					i2=i;
					j2=j;
				}
			}
		}
		if (i1==i2){
			for (int j=1;j<=j1;j++){
				time1+=s[i1].t[j];
			}
			cout<<time1<<endl;
		}
	}
	return 0;
}
