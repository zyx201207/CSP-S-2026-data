#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long d[500005],a[500005],used[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	d[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	d[1]=1;
	used[1]=0;
	int delt=a[2]-a[1];
	int isdelt=1;
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]!=delt) isdelt=0;
	} 
	if(isdelt==1){
		d[n]=1;
		for(int j=n-1;j>0;j--){
			if(used[n]+a[n]-a[j]<=m){
				used[n]+=a[n]-a[j];
				d[n]+=1;
					
			}
			else{
				break;
			}
		}
		cout<<d[n];
		return 0;
	}
	for(int i=2;i<=n;i++){
		used[i]=0;
		d[i]=1;
		for(int j=i-1;j>0;j--){
			if(used[i]+a[i]-a[j]<=m){
				used[i]+=a[i]-a[j];
				d[i]+=1;
					
			}
			else{
				break;
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(ans<d[i]) ans=d[i];
	}
	cout<<ans;
	return 0;
} 
