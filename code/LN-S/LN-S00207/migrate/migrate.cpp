#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define INF 1000000000000000099



LL c,t,n,d,ans;
vector<LL> x;
vector<LL> ick;

vector<vector<LL>> dp;
vector<vector<char>> knd;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	
	cin>>c>>t;
	for(LL tt=1;tt<=t;tt++){
		cin>>n>>d;
		x.clear();
		x.resize(n+5);
		ick.clear();
		ick.resize(n+5);
		dp.clear();
		dp.resize(n+5,vector<LL>(n+5));
		knd.clear();
		knd.resize(n+5,vector<char>(n+5,'0'));
		
		ans=0;
		
///		cout<<"n d "<<n<<" "<<d<<endl;///////
		
		for(LL i=1,ip;i<=n;i++){							

			cin>>ip;
			x[i]=ip;
			
///			cout<<"i x[i] "<<i<<" "<<x[i]<<endl;//////////
			
		}


		LL tmp;
		for(LL i=1;i<=n;i++){
///			cout<<"i "<<i<<endl;//////
			
			for(ick[i]=i;;ick[i]--){
///				cout<<"qian ick[i] "<<ick[i]<<endl;//////
				tmp=x[i]-x[ick[i]];
///				cout<<"hou  ick[i] "<<ick[i]<<endl;//////
				if(ick[i]<=0){
					ick[i]++;
					break;
				}
				if(tmp>d){
///					cout<<"!!!"<<endl;//////
					ick[i]++;
					break;
				}
			}
			
			
		}
		
				
///		///////
///		for(LL i=1;i<=n;i++){
///			cout<<ick[i]<<" ";
///		}
///		cout<<endl<<endl;
///		////
		
				
		for(LL i=1;i<=n;i++){
			dp[i][i]=0;
			for(LL j=i+1;j<=n;j++){
				dp[i][j]=INF;
				for(LL k=max(ick[j],i);k<=j-1;k++){
///					cout<<"(ijk "<<i<<j<<k<<")"<<'\n';////
///					cout<<" dp[i][j] dp[i][k] "<<dp[i][j]<<" "<<dp[i][k]<<endl;////
					if(dp[i][j]==dp[i][k]+1){
///						cout<<"!!!";////
///						cout<<knd[i][j]<<endl;////
						if(knd[i][j]=='0'){
							ans++;
	///						cout<<"++"<<endl;////
							knd[i][j]='1';
						}
						else{
							if(knd[i][j]=='1'){
								ans--;
///								cout<<"--"<<endl;////
								knd[i][j]='2';
							}
						}
					}
					dp[i][j]=min(dp[i][j],dp[i][k]+1);
				}
			}
		}
		
		
		////
		/*
		for(LL i=1;i<=n;i++){
			for(LL j=1;j<=n;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		*/
		
		
		
		
		
		
		
		
		cout<<ans<<'\n';
		
	}
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
