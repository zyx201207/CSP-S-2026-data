#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],cha[N];
int ans=1ll;
int sum=1ll;
int en;
bool taskb=1;
//priority_queue<int,vector<int>,less<int> > q;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	en=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<"1";
		return 0;
	}
	sort(a+1,a+n+1);
	int ta=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=ta){
			taskb=0;
			break;
		}
	}
	if(taskb){
		for(int i=n-1;i>=1;i--){
			if(en-(a[n]-a[i])>=0ll){
				en-=(a[n]-a[i]);
				++sum;		
			}
			else{
				break;
			}
		}
		cout<<sum;
		return 0;
	}
//	for(int i=1;i<=n;i++){
//		cha[i]=a[i]-a[i-1];
//	}
//	for(int i=1;i<=n;i++){
//		sum[i]=sum[i-1]+cha[i];
//	}
//	dp[1]=1;
//	
//	for(int i=2;i<=n;i++){
//		dp[i]=dp[i-1];
//		if(m>=i*(a[i]-a[i-1])){
//			m-=i*(a[i]-a[i-1]);
//			++dp[i];
//		}
//	}
//	cout<<dp[n];
//	int j=0;
//	for(int i=n-1;i>=1;i--){
//		if(en-(a[n]-a[i])>=0ll){
//			en-=(a[n]-a[i]);
//			q.push((a[n]-a[i]));
//			++sum;
//			j=i;		
//		}
//		else{
//			break;
//		}
//	}
//	ans=sum;
//	while(j!=0){
//		en+=q.top();
//		--sum;
//		q.pop();
//		while(j!=0&&en>=(a[j]-a[j-1])){
//			j--;
//			en-=(a[j]-a[j-1]);
//			q.push(a[j]-a[j-1]);
//			++sum;
//		}
//		ans=max(ans,sum);
//	}
	for(int i=1;i<=n;i++){
		sum=1;
		en=m;
		for(int j=i-1;j>=1;j--){
			if(en-(a[i]-a[j])>=0ll){
				en-=(a[i]-a[j]);
				++sum;
			}
			else break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
//Oct31==Dec25?
