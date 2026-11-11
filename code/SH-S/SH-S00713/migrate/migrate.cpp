#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	char ch=getchar();
	int op=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			op=-1;
		}
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return op*x;
}
const int N=2e6+9;
int C,T;
int n,d,a[N];
void solveB(){
	while(T--){
		n=read();
		d=read();
		int rcl[n+1],rcr[n+1];
		rcl[0]=rcr[0]=0;
		int r=1,l=1;
		for(int i=1;i<=n;i++){
			rcl[i]=0;
			rcr[i]=0;
			a[i]=read();
			if(a[i]-a[1]<=d){
				r=max(r,i);
				continue;
			}
		}
		while(r<=n){
			while(a[r]-a[l]>d){
				l++;
			}
			if(r==l){
				r++;
				continue;
			}
			rcl[l]++;
			if(r+1<=n&&a[r+1]-a[l]>d){
				rcr[r]++;
			}
			r++;
		}
		int ans=0;
		
//		for(int i=1;i<=n;i++){
//			cout<<rcl[i]<<' '<<rcr[i]<<endl;
//		}
		
		for(int i=1;i<n;i++){
			if(a[i+1]-a[i]>=d){
				continue;
			}
			ans+=(rcl[i]*rcr[i+1]);
		}
		cout<<ans<<'\n';
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();
	T=read();
//	if(13<=C&&C<=14){
		solveB();
//	}
	return 0;
}
