#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;
long long n,d,a[2000050],lst[2000050],cnt[2000050],nxt2[2000050],cnt2[2000050];
long long nxt[2000050],lst2[2000050],sum[2000050],sum2[2000050];
void solve(){
	cin>>n>>d;
	//cout<<n<<" "<<d<<"|";
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum2[i]=0;
	}
	
	long long j=1;
	for (int i=1;i<=n;i++){
		while (j<=i&&a[i]-a[j]>d){
			j++;
		}
		lst[i]=j;
	}
	cnt[n]=1;
	sum[lst[n]]+=1;
	for (int i=n-1;i>=1;i--){
		cnt[i]=1;
		if (lst[i+1]==i){
			cnt[i]=cnt[i+1]+1;
		}
		sum[lst[i]]+=cnt[i];
	}
	
	j=n;
	for (long long i=n;i>=1;i--){
		while (j>=i&&a[j]-a[i]>d){
			j--;
		}
		nxt2[i]=j;
	}
	cnt2[1]=1;
	sum2[nxt2[n]]+=1;
	for (int i=2;i<=n;i++){
		cnt2[i]=1;
		if (nxt2[i-1]==i){
			cnt2[i]=cnt2[i-1]+1;
		}
		sum2[nxt2[i]]+=cnt2[i];
	}
	
	
	j=n;
	for (long long i=n;i>=1;i--){
		while (j>=i&&a[j]-a[i]>d){
			j--;
		}
		nxt[i]=max(i,j-1);
	}
	j=1;
	for (long long i=1;i<=n;i++){
		while (j<=i&&a[i]-a[j]>d){
			j++;
		}
		lst2[i]=min(i,j+1);
	}
	//cout<<endl;
	long long ans=0;
	for (int i=1;i<=n;i++){
		j=nxt[i];
		int k=lst2[i];
		if (i!=j)ans+=sum[j];
		if (i!=k)ans+=sum2[k];
	}
	/*
	for (int i=1;i<=n;i++){
		cout<<lst[i]<<" "<<nxt[i]<<" "<<sum[i]<<" "<<cnt[i]<<endl;
	}
	*/
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
