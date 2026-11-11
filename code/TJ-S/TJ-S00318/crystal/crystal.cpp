#include<bits/stdc++.h>
using namespace std;
int s[500010]={0},a[500010]={0};
	
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	//cout<<1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long ansl=-1,anss=-1;
	for(int i=1;i<=n;i++){
		long long l=1,r=i;
		while(l<=r){
			long long mid=(l+r)/2;
			long long sum=s[i]-s[mid-1];
			long long re=(i-mid+1)*a[i]-sum;
			//cout<<i-mid+1<<" "<<re<<endl;
			if(re<=m){
				ansl=max(i-mid+1,ansl);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		/*
		for(int j=1;j<=n;j++){
			
			if(i-j+1<ansl) break;
			int sum=s[i]-s[j-1];
			int r=(i-j+1)*a[i]-sum;
			//cout<<i-j+1<<" "<<r<<endl;
			if(r<=m){
				ansl=max(i-j+1,ansl);
			}
		}
			*/
	}
	cout<<ansl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
