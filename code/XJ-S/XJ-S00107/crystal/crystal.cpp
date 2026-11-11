#include<bits/stdc++.h>
using namespace std;
long long a[500020];
long long dp[5000][5000],dj[5000][5000];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][0]=1;
	}
	for(int i=0;i<m;i++){
		dp[0][i]=1;
	}
	sort(a,a+n+1,cmp);

	int sum=0;

	for(int i=1;i<n;i++){
	//cout<<"I"<<i<<endl;
		for(int j=1;j<m;j++){
			//cout<<"J"<<i<<endl;
			int jm=1,pos=1;
			dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
			dj[i][j]=dj[i][j-1];
			while(jm<=j-dj[i][j-1]){
				//if(j==1&&i==3)cout<<"POS:"<<pos<<"JM:"<<jm<<"a[i-pos]:"<<a[i-pos]<<"a[i]"<<a[i]<<endl;
				if(a[i-1]+jm==a[i]){
					//cout<<a[i-1]+jm<<" "<<a[i]<<endl;
					//if(j==2&&i==2)cout<<"POS:"<<pos<<"JM:"<<jm<<"a[i-1]:"<<a[i-1]<<"a[i]"<<a[i]<<endl;
					dj[i][j]=dj[i][j-1]+jm;
					dp[i][j]=dp[i-1][j-1]+1;
					op=true;
					//cout<<"POS:"<<pos<<"JM:"<<jm<<"a[i-1]:"<<a[i-1]<<"a[i]"<<a[i]<<endl;
					//cout<<"CHANGES\n\nMAP::\n";

					//cout<<"DJ::\n";

				}
				jm++;
			}
		}
	}
	cout<<dp[n-1][m-1];
}
