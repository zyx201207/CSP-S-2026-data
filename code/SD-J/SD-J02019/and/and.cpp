#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
long long dp[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long mxn1=0,mx=-1,mxn2=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]&a[j]>=mx){
				mx=a[i]&a[j];
				mxn1=a[i],mxn2=a[j];
			}
		}
	}
	dp[1]=mxn1&mxn2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0; 
}
/*
10:24 50pts bao li dp zen me da??? my dp is yi tuo  I am sad.


%%%%%%%     %%            %%%%%       %%             %%  %%%%%%%%%%%%      %%%%%       %%%%%%%                         
  %%%       %%           %     %       %%           %%   %%               %     %        %%%
  %%%       %%          %       %       %%         %%    %%              %       %       %%%
  %%%       %%          %       %        %%       %%     %%              %       %       %%%
  %%%       %%          %       %         %%     %%      %%%%%%%%%%%%    %       %       %%%
  %%%       %%          %       %          %%   %%       %%              %       %       %%%
  %%%       %%           %     %            %% %%        %%               %     %        %%%
%%%%%%%%    %%%%%%%%%%    %%%%%              %%          %%%%%%%%%%%%      %%%%%       %%%%%%%%
*/
