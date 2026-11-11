#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int s=1;
	long long sum[100000005];
	long long cnt[100000005]={0};
	long long minn=0;
	long long a[100000005];
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]){
			s++;	
		}
	}
	if(s==n){
		cout<<n;
		return 0;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cnt[i]++;
		for(int j=1;j<n;j++){
			if(a[i]>a[j]&&a[i]>0&&a[j]>0&&i!=j){
				sum[i]=sum[i]+a[i]-a[j];
				cnt[i]++;
			}
			else if(a[i]<a[j]&&a[i]>0&&a[j]>0&&i!=j){
				sum[i]=sum[i]+a[j]-a[i];
				cnt[i]++;
			}
			else if(a[i]<0&&a[j]>0&&i!=j){
				sum[i]=sum[i]+a[j]-a[i];
				cnt[i]++;
			}
			else if(a[j]<0&&a[i]>0&&i!=j){
				sum[i]=sum[i]+a[i]-a[j];
				cnt[i]++;
			}
			else if(i!=j){
				sum[i]+=0;
				cnt[i]++;
			}
			if(sum[i]>m){
				cnt[i]--;
				break;	
			}
			minn=max(cnt[i],minn);
			
		}	
	
	}
	
	cout<<minn;
	return 0;
}
