#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,cnt;
int g[32]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
int a[N],s[30],c[N][30],b[N][30];
struct in{
	int a,b;
}d[N];
int cmp(in a,in b){
	return a.a>b.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cnt=0;
		int o=a[i];
		while(o){
			if(o%2==1) c[i][++cnt]=1;
			else c[i][++cnt]=0;
			o/=2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=30;k++){
			if(c[i][k]==1) s[k]++;
			b[i][k]=c[i][k];
		}
	}
	for(int i=1;i<=30;i++){
		if(s[i]>=m) s[i]=1;
		else s[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=30;j++){
			if(b[i][j]==1&&s[j]==1) d[i].a+=g[j],d[i].b=i;
		}
	}
	sort(d+1,d+n+1,cmp);
	int ans=a[d[1].b];
	for(int i=2;i<=m;i++) ans&=a[d[i].b];
	cout<<ans;
	return 0;
} 

