#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[600005];
long long int maxx;
long long int dp[600006];
/*
struct cmp{
	bool operator()(const int &a,const int &b)const{
		return a<b;
	}
};*/
int g;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//cout<<a[i]<<" "<<i<<endl;
	//	dp.push_back(0);
	}
	g=m;
	/*5 5
1 2 4 8 9


5 8
-3 -1 2 2 7
	*/
	dp[0]=0;
	sort(a+1,a+n+1);
	//long long int l=1e9,l1=0;
	int l=1;
	priority_queue<int> q;
	int ans=1; 
	for(int i=2;i<=n;i++){
		
		long long int k=dp[i-1]+(a[i]-a[i-1])*(i-l);
		if(k>m){
			l=i;
			dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-l);
			m=g;
			m-=dp[i-1];
			//if(dp[i-1]+(a[i]-a[i-1])<=m) ans--;
			q.push(ans);
		//	cout<<"ans="<<ans<<endl;
			ans=0;
			if(dp[i-1]+(a[i]-a[i-1])<=m) ans++;
			//ans++;
			//ans++;
			ans++;
		}else{
			dp[i]=dp[i-1]+(a[i]-a[i-1])*(i-l);
			ans++;
		}
		
		//dp.push_back()
	//	printf("i=%d,dp[%d]=%d a[%d]-a[%d]=%d a[%d]=%d\n",i,i,dp[i],i,i-1,a[i]-a[i-1],i,a[i]);
		
	}
	//if(q.size()==1) ans=n-q.top();
	q.push(ans);
	//int *w=dp+1;
	
	//int p=fs-dp;
	int p=q.top();
	/*
	for(int i=l;i<=n;i++){
		if(dp[i]<=m){
			p++;
			//break;
		}
	}*/
	//long long *w=lower_bound(dp.begin(),dp.end(),m);
	cout<<p<<endl;
	return 0; 

}
