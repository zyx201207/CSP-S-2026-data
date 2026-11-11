#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=4e5+10;
int a[N];
int b[N];
bool dp[N][35]={};
int read(){
	char ch;
	int x=0,f=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}return x*f;
}int max(int _,int __){
	return _>__?_:__;
}void bt(int x,int k){
	int wei=30;
	while(x){
		if(x%2==1) dp[k][wei]=1;
		else dp[k][wei]=0;
		x/=2;
		wei--;
	}
}int pow(int q,int qq){
	int ret=1;
	if(qq<=0) return ret;
	while(qq){
		if(qq%2) ret*=q;
		q*=q;
		qq>>=1;
	}return ret;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int ans=0;
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		bt(a[i],i);
	}
	if(m==1){
		int mx=-1;
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}else if(m==2){
		int mx=-1;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) mx=max(mx,a[i]&a[j]);
		cout<<mx;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=30;j++){
				if(dp[i][j]==1) b[j]++;	
			}
		}for(int i=1;i<=30;i++){
			if(b[i]>=m) continue;
			if(b[i]<m){
				for(int j=1;j<=n;j++){
					if(dp[j][i]==1){
						dp[j][i]=0;
						a[j]-=pow(2,30-i);
					}
				}
			}
		}for(int i=1;i<=30;i++) b[i]=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=30;j++){
				if(dp[i][j]==1) b[j]++;	
			}
		}int flag=1;
		for(int i=1;i<=30;i++){
			if(b[i]<m) continue;
			if(b[i]>=m){
				for(int j=1;j<=n;j++){
					if(dp[j][i]==0){
						flag++;
						a[j]=0;
					}for(int k=1;k<=30;k++){
						if(dp[j][k]==1){
							b[k]--;
							dp[j][k]=0;
						}
					}
				}
				for(int j=1;j<flag+b[i]-m;j++){
					a[j]=0;
					for(int k=1;k<=30;k++){
						if(dp[j][k]==1){
							b[k]--;
							dp[j][k]=0;
						}
					}
				}
				ans+=pow(2,30-i);
				flag=b[i]-m;
			}
		}
		cout<<ans;
	}return 0;
}
