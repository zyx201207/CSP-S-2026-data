#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],dp[2050][1010];
int n,m;
bool cheak(int x){
	x=x+1;
	while(x!=1){
		if(x%2) return 0;
		x/=2;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i<=2020) dp[i][1]=a[i];
	}
	int flag=1;
	for(int i=1;i<=n;i++){
		if(!cheak(a[i])){
			flag=0;
			break;
		}
	}
	
	//texing1
	
	if(flag==1){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	int flag2=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1){
			flag2=0;
			break;
		}
	}
	
	
	
	//texinng2
	if(flag2==1){
		cout<<n-m;
		return 0;
	}
	//tepan
	if(m==n){
		int cnt=a[1];
		for(int i=1;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	
	//maxa<4
	int flag3=1;
	for(int i=1;i<=n;i++){
		if(a[i]>=4){
			flag3=0;
			break;
		}
	}
	if(flag3==1){//?
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt1++;
			if(a[i]==2) cnt2++;
			if(a[i]==3) cnt3++;
		}
		if(cnt3>=m) cout<<3;
		else if(cnt3+cnt2>=m) cout<<2;
		else if(cnt3+cnt1>=m) cout<<1;
		else cout<<0; 
		return 0;
	}
	
	if(m==n-1){
		int cnt=2147483647,maxx=0;
		for(int i=1;i<=n;i++){ 
			cnt=2147483647;
			for(int j=1;j<=m;j++){
				if(j!=i)cnt=cnt&a[j];
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
		return 0;
	}
	
	if(n<=5000&&m<=5000){//bl
		for(int i=1;i<=n;i++){
			for(int k=1;k<i;k++){
				for(int j=1;j<=m;j++){
					dp[i][j]=max(dp[k][j-1]&a[i],dp[i][j]);
				}
			} 	
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt=max(cnt,dp[i][m]);
		}
		cout<<cnt;
		return 0;
	}
	else{//luangao
		int cnt=0,maxx=0;
		sort(a+1,a+n+1);
		for(int i=n;i>=n-100;i--){
			cnt=a[i];
			for(int j=i;j>=i-m+1;j--){
				cnt=cnt&a[j];
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
	}
}
//oIo luangao
//ferloser feropen
