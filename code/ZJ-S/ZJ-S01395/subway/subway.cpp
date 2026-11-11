#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
long long a[500044],s[500044][22][2];
long long d[504][504];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d1,q;
	c=read();n=read();m=read();d1=read();q=read();
	for(int i=1;i<=m;i++){
		a[i]=read();
	}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++){
		d[i][i]=0;
		int sl,ai,ti;
		sl=read();
		for(int j=1;j<=sl;j++){
			ai=read();ti=read();
			s[ai][0][0]++;
			s[ai][s[ai][0][0]][0]=i;s[ai][s[ai][0][0]][1]=ti;
		}
	}
	long long sum;
	for(int i=1;i<=m;i++){
		int sl=s[i][0][0];
		for(int j=1;j<=sl;j++){
			for(int k=j+1;k<=sl;k++){
				sum=s[i][j][1]+s[i][k][1];
				if(d[s[i][j][0]][s[i][k][0]]>sum){
					d[s[i][j][0]][s[i][k][0]]=sum;
					d[s[i][k][0]][s[i][j][0]]=sum;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(k==i||k==j)continue;
				sum=d[i][k]+d[k][j];
				if(d[i][j]>sum){
					d[i][j]=sum;d[j][i]=sum;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int xi,yi,slx,sly;
		xi=read();yi=read();
		slx=s[xi][0][0];sly=s[yi][0][0];
		long long ans=LLONG_MAX;
		for(int j=1;j<=slx;j++){
			for(int k=1;k<=sly;k++){
				sum=d[s[xi][j][0]][s[yi][k][0]]+s[xi][j][1]+s[yi][k][1];
				if(ans>sum){
					ans=sum;
				}
			}
		}
		cout<<ans+a[xi]+a[yi]<<"\n";
	}
	return 0;
}