#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2000005;
int T;
int read() {
	char ch=getchar();
	while((!(ch>='0' && ch<='9')) && ch!='-') {
		ch=getchar();
	}
	int FLAG=0;
	if(ch=='-'){
		FLAG=1;
		ch=getchar();
	}
	int ans=0;
	while(ch>='0' && ch<='9') {
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	if(FLAG){
		ans=-ans;
	}
	return ans;
}
int opt;
int n,D;
int X[N];
int dp[N],sum[N],dst[N];
int dan;
void doit(int st){
	sum[0]=0;
	for(int i=1;i<=n;i++) {
		dp[i]=0;
		sum[i]=0;
		dst[i]=0;
	}
	if(X[st+1]-X[st] >D) return ;
	int j=st,k=st; 
	dp[st]=1;
	sum[st]=1;
	for(int i=st+1;i<=n;i++) {
		if(X[i]-X[i-1] >D ) return ;
		while(j<i && X[i]-X[j]>D) {
			j++;
		}
		while(k+1<i && dst[k+1]==dst[j]) {
			k++;
		}
		dst[i]=dst[j]+1;
		dp[i]=sum[k]-sum[j-1];
		dp[i]=min(dp[i],3ll);
		sum[i]=sum[i-1]+dp[i];
		if(dp[i]==2) {
			dan++;
		}
	}
	
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	opt=read();
	T=read();
	if(opt==11|| opt==12) {
		while(T--) {
			dan=0;
			n=read(); D=read();
			
			for(int i=1;i<=n;i++) {
				X[i]=read();
			}
			if(n==1 || n==2){
				printf("0\n");
				continue;
			}
			int val=X[2]-X[1];
			int chu=D/val;
//			cout<<n<<" "<<D<<" "<<chu<<endl;
			if(chu<=1) {
				printf("0\n");
				continue;
			}
			else {
				for(int i=1;i<=n-1;i++) {
					if(n-i >=2*chu-1) {
						dan++;
					}
				}
				printf("%lld\n",dan);
			}
		}
		return 0;
	} 
	while(T--) {
		dan=0;
		n=read(); D=read();
		for(int i=1;i<=n;i++) {
			X[i]=read();
		}
		for(int st=1;st<=n;st++) {
			doit(st);
		}
		printf("%lld\n",dan);
	}
	return 0;
} 
