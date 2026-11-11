#include<bits/stdc++.h>
using namespace std;
int n,ans=-1e9,chan,cnt;
long long m,a[500005],cha[500005],sum,maxn=-1e9,cal[105];
bool flag=1;
void solve1(){
	for(int j=n;j>=1;j--){
		sum+=(a[n]-a[j]);
		cnt++;
		if(sum==m){
			ans=max(ans,cnt);
			break;
		}
		if(sum>m){
			ans=max(ans,cnt-1);
			break;
		}
	}
	cout<<cnt;
} //30pts
void solve2(){
	for(int i=-105;i<=105;i++){
		cnt=0;
		sum=0;
		for(int j=n;j>=1;j--){
			if(a[j]<=i){
				sum+=(i-a[j]);
				cnt++;
			}
			if(sum==m){
			    ans=max(ans,cnt);
			    break;
		    }
		    if(sum>m){
			    ans=max(ans,cnt-1);
			    break;
		    }
		}
	}
	cout<<ans;
}//25pts
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&flag==1){
			chan=a[2]-a[1];
			int cha=a[i]-a[i-1];
			if(chan!=cha) flag=0;
		}
		maxn=max(maxn,a[i]);
	}
	if(flag==1){
		solve1();
		return 0;
	}
	sort(a+1,a+n+1);
	if(maxn<=100&&n>5000){
		solve2();
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum=0;
		cnt=0;
		for(int j=i;j>=1;j--){
			sum+=(a[i]-a[j]);
			cnt++;
			if(sum==m){
				ans=max(ans,cnt);
				break;
			}
			if(sum>m){
				ans=max(ans,cnt-1);
				break;
			}
		}
	}
	cout<<ans;//35pts
	fclose(stdin);
	fclose(stdout);
	return 0;
}
