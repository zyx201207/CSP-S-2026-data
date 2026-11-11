#include<bits/stdc++.h>
using namespace std;
int n;
int m,ans;
int dp[50050];
int a[100010],b[100010];
int he(){
	int cnt=0,ns=0;
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(int i=2;i<=n;i++){
		if(b[i]==b[i-1]){
			cnt=1;
			while(b[i]==b[i-1]){
				
				cnt++;
				i++;
			}
			ns=max(ns,cnt);
		}
	}
	return ns;
	
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
   
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[n]+=1;
			while(dp[j-1]<he()){
				a[n]+=1;
				dp[j]=he();
			}
			
			if(dp[j-1]<he()){
			}
			else{
				dp[j]=dp[j-1];
				a[n]--;
			}
		}
	}
    cout<<n;
    
    return 0;
}

//5 8
// -3 -1 2 2 7
