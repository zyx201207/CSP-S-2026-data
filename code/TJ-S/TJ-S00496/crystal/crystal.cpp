#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],b[500100][5],ma=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//-------------------------
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	b[1][1]=1;
	b[1][2]=m;
	for(int i=2;i<=n;i++){
		long long y=b[i-1][2];
		long long x=b[i-1][1]*(a[i]-a[i-1]);
		if(y>=x){
			b[i][2]=y-x;
			b[i][1]=b[i-1][1]+1;
		}else{
			long long cnt=0;
			while(y<x){
				y+=a[i-1]-a[i-b[i-1][1]+cnt];
				x-=a[i]-a[i-1];
				cnt++;
			}
			b[i][2]=y-x;
			b[i][1]=b[i-1][1]+1-cnt;
		}
		ma=max(ma,b[i][1]);
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<':'<<a[i]<<endl;
//	}
//	cout<<"----------------------------------------------------------\n";
//	for(int i=1;i<=n;i++){
//		cout<<i<<':'<<b[i][1]<<' '<<b[i][2]<<endl;
//	}
	printf("%lld",ma);
	//-------------------------
	fclose(stdin);
	fclose(stdout);
	return 0;
}
