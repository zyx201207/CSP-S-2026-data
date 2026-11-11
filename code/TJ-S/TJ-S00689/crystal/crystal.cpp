#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//const ll MAXN=1e15;
long long n,m;
long long a[100010];
long long cz[100010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	long long zh=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zh+=a[i];
	}
	zh=zh/n;
	for(int i=1;i<=n;i++){
		cz[i]=abs(zh-a[i]);
	}
	sort(cz+1,cz+1+n);
	long long  ans=0;
	for(int i=1;i<=n;i++){
		//cout<<"i="<<i<<" ";
		//cout<<"cz[i]="<<cz[i]<<" ";
		if(cz[i]==0){
			ans+=1;
			//cout<<"ans+=1,ans="<<ans<<" ";
		}else if(m>=cz[i]){
			//cout<<"ans++"<<" ";
			m-=cz[i];
			//cout<<"m-cz[i]="<<m<<" ";
			ans++;
		}else{
			//cout<<"break";
			break;
		}
	}
	cout<<ans;
	
	return 0;
} 
