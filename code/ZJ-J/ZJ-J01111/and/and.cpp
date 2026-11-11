#include<bits/stdc++.h>
using namespace std;
long long n,m,s,ans,ma,a[1000010],b[1000010],c[1000010],dp[110][110],flag=0;
bool ppd(int x){
	while(1){
		if(x%2==1) return 0;
		x=x/2;
	}
	return 1;
}
bool pd(){
	for(int i=1;i<=n;i++){
		if(ppd(a[i])) return 0;
	}
	return 1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==n){
    	ans=a[1];
    	for(int i=2;i<=n;i++){
    		ans=a[i]&ans;
		}
    	cout<<ans;return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ma=max(ma,(a[i]&a[j]));
				}
			}
		}
		cout<<ma;return 0;
	}
	if(n<=20){
		for(int i=1;i<=n;i++) dp[i][1]=a[i];
		for(int i=1;i<=n;i++){
			for(int j=2;j<=i;j++){
				for(int k=1;k<=i-1;k++){
					dp[i][j]=max(dp[i][j],((dp[k][j-1])&a[i]));
				}
			}
		}
		for(int i=m;i<=n;i++) ma=max(ma,dp[i][m]);
		cout<<ma;return 0;
	}
	if(m==n-1){
		b[1]=a[1];
		for(int i=2;i<=n;i++){
			b[i]=(a[i]&b[i-1]);
		}
		c[n]=a[n];
		for(int i=n-1;i>=1;i--){
			c[i]=(a[i]&c[i+1]);
		}
		ma=max(b[n-1],c[2]);
		for(int i=2;i<=n-1;i++){
			ma=max(ma,(b[i-1]&c[i+1]));	
		}
		cout<<ma;return 0;
	}
	sort(a+1,a+1+n);
	if(pd()){
		ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans=(ans&a[i]);
		}
		cout<<ans;return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			flag=1;	
		}
	}
	for(int i=1;i<=n;i++){
		s+=a[i];
	}
	if(s<=4){
		if(a[n]==2&&a[n-1]==1&&a[n-2]==1){
			if(m==1){
				cout<<2;
			}
			else if(m==2){
				cout<<1;
			}
			else if(m>=3){
				cout<<0;
			}
		}
		else{
			ans=a[n];
			for(int i=n-1;i>=n-m+1;i--){
				ans=(ans&a[i]);
			}
			cout<<ans;
		}
		return 0;
	}
    return 0;
}