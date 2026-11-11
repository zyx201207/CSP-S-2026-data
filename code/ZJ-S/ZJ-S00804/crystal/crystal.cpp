#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],sum[N],k[205];
bool f,f1,f2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i) f=1;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) f1=1;
		if(abs(a[i])>100) f2=1;
	}	
	sort(a+1,a+n+1);
	if(n<=5000){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			long long mm=m,ans1=1;
			for(int j=i-1;j>=1;j--){
				if(a[i]<a[j]) continue;
				if(mm-abs(a[i]-a[j])>=0){
					mm-=(a[i]-a[j]);
					ans1++;
	//				cout<<i<<" "<<j<<" "<<mm<<" "<<ans1<<"\n";
				}
			}
			maxx=max(maxx,ans1);
		}
		cout<<maxx;
		
		return 0;
	}
	if(!f){
		long long sum=0;
		for(int i=1;i<n;i++){
			sum+=i;
			if(sum>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
		//A 15tps
	}
	else if(!f1){
		long long cha=a[2]-a[1],sum=0;
		for(int i=1;i<=n;i++){
			sum+=i*cha;
			if(sum>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
		return 0;
		//B 15tps
	}
	else if(!f2){
		for(int i=1;i<=n;i++){
			k[a[i]+100]++;
		}
		long long ans=0;
		for(int i=200;i>=0;i--){
			long long mm=m,ans1=k[i];
			for(int j=i-1;j>=0;j--){
				if(k[j]==0) continue;
				if(mm-(i-j)*k[j]>0){
					ans1+=k[j];
					mm-=(i-j)*k[j];
	//				cout<<i<<" "<<j<<" "<<mm<<" "<<ans1<<"\n";
				}
				else{
					ans1+=mm/(j-i);
					break;
				}
			}
			ans=max(ans,ans1+1);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

