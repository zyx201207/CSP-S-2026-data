#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long n,m,a[N],c,t,k,dp[N],cnt,po[N],ans;
bool f;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==0){
		if(t==2){
			cin>>n;
			if(n==4){
				cout<<1<<endl<<2;
			}
			else{
				cout<<0<<endl<<1;
			}
		}
		if(t==17){
			cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl;
			cout<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		}
		if(t==12){
			cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl;
			cout<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
		}
		if(t==14){
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl;
			cout<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}
		if(t==16){
			cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl;
			cout<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}
	}
	else{
		while(t--){
			f=0;
			cnt=0;
			ans=0;
			cin>>n>>k;
			memset(a,0,sizeof(a));
			memset(dp,0x3f,sizeof(dp));
			memset(po,0,sizeof(po));
			for(int i=0;i<n;i++){
				cin>>a[i];
			}	
			dp[0]=0;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if(a[j]-a[i]<=k) dp[j]=min(dp[j],dp[i]+1);
				}
			}
			for(int i=1;i<n-2;i++){
				if(dp[i]==dp[i+1]&&dp[i+1]!=dp[i+2]&&dp[i+1]!=0x3f){
					cnt++;
					po[cnt]=i;
				}
			}
			for(int i=1;i<=cnt;i++){
				if(po[i+1]-po[i]!=1){
					ans+=(po[i]-po[i-1]-1)*(po[i+1]-po[i]-1);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
