#include<bits/stdc++.h>
using namespace std;
const int maxl=500005;
long long a[maxl];
int dp[maxl];
int leenn[maxl];
vector<int> dlp[maxl];
int main(){
  freopen("crystal",'w',"crystal.in");
  freopen("crystal",'r',"crystal.out");
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
    	cin>>a[i];
    }

    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(i==j){
    			continue;
    		}
    		if((a[i]-a[j])==0){
    			dp[i]+=1;
    		}
    		if((a[i]-a[j])<0){
    			dlp[i].push_back(a[j]-a[i]);
    			leenn[i]+=1;
    		}
    		else if(a[i]-a[j]>0){
    			dlp[i].push_back(a[i]-a[j]);
    			leenn[i]+=1;
    		}
    	}
    }
    for(int i=0;i<n;i++){
            int x=leenn[i];
        long long ff[x];
        for(int j=0;j<x;j++){
            ff[j]=dlp[i][j];
        }
    	sort(ff,ff+x);
    	long long ans=0;
    	int a=0;
    	for(int j=0;j<x;j++){
            ans+=ff[j];
            if(ans>m){
                break;
            }
            a++;
    	}
    	dp[i]+=a;
    }
    sort(dp,dp+n);
    cout<<dp[n-1]+1;
    return 0;
}
