#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],sum[500010],nsum[500010],num[200010],ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0)num[100000+(-1*a[i])]+=1;
		else num[a[i]]+=1;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(a[i]==a[i-1]&&i>1)nsum[i]=nsum[i-1];
		else{
			if(a[i]>=0&&a[i-1]>=0)nsum[i]=num[a[i]]+nsum[i-1];
			else if(a[i]>=0&&a[i-1]<0)nsum[i]=num[a[i]]+nsum[i-1];
			else if(a[i]<0&&a[i-1]>=0)nsum[i]=num[100000+(-1*a[i])]+nsum[i-1];
			else{
				nsum[i]=num[100000+(-1*a[i])]+nsum[i-1];
				//cout<<endl<<num[100000+(-1*a[i])]<<" "<<nsum[i-1]<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int val=(j-i+1)*a[j]-(sum[j]-sum[i-1]);
			if(val>m){
				//cout<<nsum[j-1]-nsum[i-1]<<" "<<j*a[j]<<(sum[j]-sum[i-1])<<endl;
				//cout<<i<<" "<<j<<nsum[j-1]<<" "<<nsum[i-1]<<endl;
				ans=max(nsum[j-1]-nsum[i-1],ans);
				break;
			}
			else if(val==m){
				
				ans=max(nsum[j]-nsum[i-1],ans);
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
