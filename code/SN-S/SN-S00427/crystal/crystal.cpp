#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;

int n,m;
int a[N];
int s[N];

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	for(int i=n;i>=1;i++) s[i]=s[i+1]+a[i];
	
	int ans=0;
	for(int i=1;i<=n;i++){ //let aj -> ai
		int sum=0,j=i-1,cnt=0;
		while(j>=1){
			if(sum+(a[i]-a[j])>m) break;
			sum+=(a[i]-a[j]);
			j--; cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans+1;
	
	return 0;
	
}

//#include <bits/stdc++.h>
//using namespace std;
//#define int long long
//const int N=5e5+10;
//
//int n,m;
//int a[N];
//int s[N];
//
//bool check(int x){
//	//检测a[x]是否能作为最终到达的目标 
//	if(x==315275){
//		cout<<x*a[x]-s[x]<<" "<<m<<"\n";
//	}
//	int sum=0;
//	for(int i=1;i<=x;i++){
//		sum+=a[x]-a[i];
//		if(sum>m) return 0; //避免溢出 
//	}
//	if(sum<=m) return 1;
//	else return 0;
//}
//
//void find(int l,int r){
//	int ans=-1;
//	while(l<=r){
//		int mid=(l+r)/2;
//		if(check(mid)) ans=mid,l=mid+1;
//		else r=mid-1;
//	}
//	cout<<ans;
//}
//
//signed main(){
//	
//	freopen("crystal4.in","r",stdin);
//	//freopen("crystal.out","w",stdout);
//	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	
//	cin>>n>>m;
//	
//	s[0]=0;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	
//	sort(a+1,a+1+n);
//	
//	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
//	
//	for(int i=1;i<=n;i++){ //let aj -> ai
//		int sum=(i-1)*a[i]-s[i-1];
//		int sum1=0;
//		for(int j=1;j<=i;j++){
//			sum1+=a[i]-a[j];
//		}
//		if(i==315275){
//			cout<<sum<<" "<<sum1<<" "<<m<<"\n";
//		}
//		//for(int j=1;j<i;j++) sum1+=(a[i]-a[j]);
//		if(sum<=m && sum>=0){
//			cout<<i;
//			return 0;
//		}
//	}
//	//313324
////	cout<<check(315275);
////	find(1,5e5);
//	
//	//sum1=a5-a1+a5-a2+a5-a3+a5-a4+a5-a5
//	
//	return 0;
//	
//}
