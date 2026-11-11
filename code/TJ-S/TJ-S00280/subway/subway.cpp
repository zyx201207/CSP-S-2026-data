#include<bits/stdc++.h>
using namespace std;
int c;
long long n,m,d,q,k,cnt;
long long t[100100];
long long x1,y1,x2,y2;
long long s1[100100],s2[100100],t1[100100],t2[100100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&t[i]);
	}
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>s1[i]>>t1[i];
		}
	}
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>s2[i]>>t2[i];
		}
	}
	cin>>x1>>y1>>x2>>y2;
	for(int i=x1;i<=y1;i++){
		cnt=t[i]+t1[i];
	}
	cout<<cnt;
	for(int i=x2;i<=y2;i++){
		cnt=t[i]+t2[i];
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

