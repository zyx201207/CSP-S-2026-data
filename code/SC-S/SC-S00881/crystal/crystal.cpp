#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],num[500050],sum[500050];
struct node{
	long long num,cntt;
};
vector<node> vp[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		sum[i]=a[i]-a[i-1];
		vp[2].push_back({sum[i],1});
	}
	num[2]=sum[2];
	num[1]=a[1];
	for(int i=2;i<=n;i++){
		int cnt=1;
		memset(num,0,sizeof(num));
		for(int j=i;j<=n;j++){
			num[j]=num[j-1]+sum[j]*cnt;
			vp[i].push_back({num[j],cnt});
			cnt++;
		}
		
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		//cout<<num[i]<<" ";
		for(auto j:vp[i]){
			//cout<<j<<" ";
			if(j.num<=m){
				int vv=j.cntt;
				ans=max(ans,vv);
			}
		}
		//cout<<endl;
	}
	cout<<ans+1;
	/*
	long long cnt=a[n]-a[n-1],ans=0;
	while(m-cnt>=0){
		m-=cnt;
		cnt+=(a[n]-a[n-1]);
		ans++;
	}
	cout<<ans;
	*/
	return 0;
}
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/