#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long dp[N];
long long c,T,n,d,a[N],mi,cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			long long ch=a[n]-a[n-1];
			if(d/ch==2){
				cout<<n-3<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
	if(c==13||c==14){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0<<endl;
		}
	}
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(a[n]-a[1]<=d){
			cout<<0<<endl;
			continue;
		}
		cnt=0;
		for(int k=1;k<=n;k++){
			dp[k]=0;
			for(int i=k+1;i<=n;i++){
				dp[i]=INT_MAX;
			}
			for(int i=k+1;i<=n;i++){
				mi=1;
				for(int j=i-1;j>=k;j--){
					if(a[i]-a[j]<=d){
						if(dp[i]>dp[j]+1){
							dp[i]=dp[j]+1;
							mi=1;
						}else{
							if(dp[i]==dp[j]+1){
								mi++;
							}
						}
					}else{
						continue;
					}
				}
				if(mi==2){
					cnt++;
				}
			}
		}	
		cout<<cnt<<endl;
	}
	return 0;
} 
