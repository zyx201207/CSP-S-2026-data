#include<bits/stdc++.h>
using namespace std;
int n;
int m;
const int MAXN=2*10*10*10*10*10+33;
long long a[MAXN];
long long dp[MAXN];
long long ans=0;
int main(){
	freopen("and3.in","r",stdin);
	freopen("and3.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	cin>>m;
	dp[0]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	//if(n<=20){
		if(n==1){
			ans=a[1];
			return 0;
		}
		else if(n==2){
			
			if(m==1){
				ans=max(a[1],a[2]);
			}
			if(m==2){
				ans=a[1]&a[2];
			}
		}
		else if(m==1){
			for(int i=1;i<=n;i++){
				ans=max(a[i],ans);
			}
		}
		else if(n==3){
			if(m==2)ans=max(a[1]&a[2],max(a[1]&a[3],a[2]&a[3]));
			if(m==3)ans=a[1]&a[2]&a[3];
		}
		else if(n==4){
			if(m==2)ans=max(a[1]&a[2],max(a[1]&a[3],max(a[2]&a[3],max(a[2]&a[4],max(a[3]&a[4],a[1]&a[4])))));
			if(m==3)ans=max(a[1]&a[2]&a[3],max(a[1]&a[2]&a[4],a[2]&a[3]&a[4]));
			if(m==4)ans=a[1]&a[2]&a[3]&a[4];
		}
		else if(n==5){
			if(m==2)ans=max(a[1]&a[2],max(a[1]&a[3],max(a[2]&a[3],max(a[2]&a[4],max(a[3]&a[4],max(a[1]&a[5],max(a[2]&a[5],max(a[3]&a[5],max(a[4]&a[5],a[1]&a[4])))))))));
			if(m==3)ans=max(a[1]&a[2]&a[3],max(a[1]&a[2]&a[4],max(a[1]&a[2]&a[5],max(a[1]&a[3]&a[5],max(a[1]&a[4]&a[5],max(a[2]&a[3]&a[5],max(a[2]&a[4]&a[5],max(a[3]&a[4]&a[5],a[2]&a[3]&a[4]))))))));
			if(m==4)ans=max(a[1]&a[2]&a[3]&a[4],max(a[2]&a[3]&a[4]&a[5],max(a[1]&a[2]&a[3]&a[5],a[1]&a[3]&a[4]&a[5])));
			if(m==5)ans=a[1]&a[2]&a[3]&a[4]&a[5];
		} 
	
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
	}
	if(m==n){
		
		for(int i=2;i<=n;i++){
			a[1]&=a[i];
		}
		ans=a[1];
	}
	cout<<ans;
	return 0;
}
