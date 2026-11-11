#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int t[N];
int ans[N];
int sum[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnta=0,cntb=0;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		if(t[i]==1){
			cnta++;
		}else{
			cntb++;
		}
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		if(t[n]==2){
			if(cntb>1&&t[n]==2){
				cout<<"0 "<<n;
				return 0;
			}
			if(cntb==1&&t[n]==2){
				cout<<n-1<<" "<<n;
				return 0;
			}
		}
		if(t[n]==1){
			if(cnta>1&&t[n]==1){
				cout<<n<<" 0";
				return 0;
			}
			if(cnta==1&&t[n]==1){
				cout<<n<<" "<<n-1;
				return 0;
			}
		}
	}
	else{
		for(int i=1,j=1;i<=n,j<=m;i++){
			if(i==1){
				sum[j]=1;
			}
			if(i!=1&&t[i-1]==t[i]){
				sum[j]=i;
			}if(i!=1&&t[i-1]!=t[i]){
				j++;
				sum[j]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
	}
	return 0;
}
