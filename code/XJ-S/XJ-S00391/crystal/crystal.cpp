#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500005],dp[500005]={0};
int maxx=0;

void erfen(int rr){
//	cout << rr << endl;
	int l = 1,mid,r=rr;
	long long bijiao,zong;
	while(1){
		mid=(l+r)/2;
//		cout <<"  "<< l << ' '<<mid<<' '<<r<<endl;
		bijiao = dp[rr]-dp[mid-1];
		zong = (rr-mid+1)*a[rr];
//		cout << "  bijiao:"<<bijiao<<"zong:"<<zong<<endl;
		if(zong-bijiao<=m){
			r=mid-1;
		}else if(zong-bijiao>m){
			l=mid+1;
		}
		if(l>r){
			maxx=max(rr-l+1,maxx);
//			cout << "  "<<rr-l+1<<endl;
			return;
		}
	}
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		dp[i]=dp[i-1]+a[i];
	}
	for(int i = 1;i<=n;i++){
		erfen(i);
	}
	cout << maxx;
	return 0;
} 
