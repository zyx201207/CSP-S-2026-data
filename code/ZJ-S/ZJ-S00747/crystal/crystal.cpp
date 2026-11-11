#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],ans=0;
bool f,ff;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=true;
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])ff=true;
		}
	}
	if(f==false){
		long long sum=0,cnt=1;
		while(sum<=m){
			sum+=cnt;
			cnt++;
		}
		cout<<cnt-1;
		return 0;
	}
	if(ff==false){
		long long sum=0,cnt=a[2]-a[1],num=0;
		while(sum<=m){
			num++;
			sum+=cnt;
			cnt+=(a[2]-a[1]);
		}
		cout<<num;
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		long long j=i+1,cnt=1,sum=0;
		while(j<=n){
			sum+=(a[j]-a[i]);
			if(sum>m)break;
			cnt++; 
			j++;
		}
		long long k=j;
		while(a[k]==a[k-1]&&k<=n){
			cnt++,k++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}	