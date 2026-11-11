using namespace std;
#include<bits/stdc++.h>
int c;int t;
long long x[2000006];

void solve(){
	int n;long long d;
	long long ans=0;
	cin>>n;cin>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if((c==11)||(c==12)){
		int delta=x[2]-x[1];
		if(d<delta*2){
			cout<<0<<endl;
		}
		else if(d/delta==2){
			if(n<4){
				cout<<0<<endl;
			}
			else{
				cout<<(n-4+1)<<endl;
			}
		}
		else{
			if((n-((d/delta)*((d/delta)-1)+2)+1)<0){
				cout<<0<<endl;
			}
			cout<<(n-((d/delta)*((d/delta)-1)+2)+1)<<endl;
		} 
	}
	else{
		for(int i=1;i<n;i++){
			int dp[n-i+11][2];
			dp[1][1]=1;dp[1][2]=1;
			for(int j=i+2;j<=n-i;j++){
				if(x[j]-x[j-1]>d){
					dp[j][1]=-1;
					break;
				}
				else{
					int min=dp[j-1][1]+1;
					int mincnt=1;
					int back=2;
					while(x[j]-x[j-back]<=d){
						if(dp[j-back][1]+1==min){
							mincnt+=dp[j-back][2];
						}
						if(dp[j-back][1]+1<min){
							mincnt=dp[j-back][2]+1;
							min=dp[j-back][1]+1;
						}
						back++;
					}
					if(mincnt==2){
						ans++;
					}
					dp[j][2]=mincnt;
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return;	
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c;cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}

