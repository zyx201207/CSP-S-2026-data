#include <bits/stdc++.h>
using namespace std;
#define int long long
uint8_t buf[1<<20];
int p1;
char gc(){
	if(p1==1<<20){
		p1=0;
		fread(buf,1,1<<20,stdin);
		return buf[p1++];
	}
	return buf[p1++];
}
void read(long long &a){
	a=0;
	long long flag=1;
	char c;
	do{c=gc();if((c>='0'&&c<='9')||c=='-') break;}while(1);
	if(c=='-') flag=-1,c=gc();
	while(c>='0'&&c<='9'){
		a*=10;a+=c-'0';c=gc();
	}
	a*=flag;
}
int c,t;
int n,m;
int x[2000010];
pair<int,int> dp[1010][1010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c);read(t);
	if(c==11||c==12){
		for(int _=1;_<=t;++_){
			read(n);read(m);
			for(int i=1;i<=n;++i){
				read(x[i]);
			}
			int d=x[2]-x[1];
			m/=d;
			if(m<2){
				printf("0\n");
				continue;
			}
			m*=2;
			m--;
			if(m>=n){
				printf("0\n");
				continue;
			}
			printf("%d\n",n-m);
		}
		return 0;
	}else{
		for(int _=1;_<=t;++_){
			read(n);read(m);
			for(int i=1;i<=n;++i){
				read(x[i]);
			}
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					dp[i][j].first=0x66ccff66ccffll;
					dp[i][j].second=0;
				}
			}
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(abs(x[i]-x[j])<=m){
						dp[i][j].first=1;
						dp[i][j].second=1;
					}
				}
				dp[i][i].first=0x66ccff66ccffll;
			}
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					for(int k=1;k<=n;++k){
						if(dp[j][k].first>dp[j][i].first+dp[i][k].first){
							dp[j][k].first=dp[j][i].first+dp[i][k].first;
							dp[j][k].second=dp[j][i].second*dp[i][k].second;
						}else
						if(dp[j][k].first==dp[j][i].first+dp[i][k].first){
							dp[j][k].second+=dp[j][i].second*dp[i][k].second;
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<=n;++i){
				for(int k=1;k<i;++k){
					if(dp[i][k].second==2){
						ans++;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
