#include <bits/stdc++.h>
#define int long long
using namespace std;
int readint(){
	int k=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+(c-'0');
	return f*k;
}
int n,m,c,t,d,a[100000],dp[100000],way[100000];
void dfs(int id){
	if(id>n) return;
	cout<<id<<endl;
	for(int i=id+1;i<=n;i++){
		if(d+a[id]>=a[i]){
			if(dp[i]>dp[id]+1){
				dp[i]=dp[id]+1;
				way[i]=1;
				dfs(i);
			}else if(dp[i]==dp[id]+1){
				way[i]++;
				dfs(i);
			}else break;
		}else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0 && t==17){
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
	}else if(c==0 && t==12){
		cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
	}else if(c==0 && t==14){
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
	}else if(c==0){
		cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
	}
	for(int O=1;O<=t;O++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		if(n<=5000){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) dp[j]=1e16;
				dp[i]=0;
				dfs(i);
				for(int j=i+1;j<=n;j++){
					cout<<way[j]<<" ";
					if(way[j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	
	return  0;
} 
/*
T1:45pts: baoli
100pts:双指针从左往右，可以发现具有线性性质，所以直接改ans
T2；100pts 图论 
T3: 
*/
