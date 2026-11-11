#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0,f=0,fn=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>=3){
		cin>>a[1]>>a[2];
		fn=a[2]-a[1];
		for(int i=3;i<=n;i++){
			scanf("%lld",&a[i]);
			if((a[i]-a[i-1])!=fn){
				f=1;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
	}
	if(!f){
		if(fn==1){
			long long y=m;
			long long i=1;
			while(1){
				y=y-(i+1);
				//cout<<i<<" "<<fn<<" "<<y<<endl;
				if(y<=0){
					break;
				}
				i++;
			}
			cout<<i+1<<endl;
			return 0;
		}
		else{
			long long y=m;
			if(y<fn){
				cout<<"1";
				return 0;
			}
			long long i=0;
			y=y-fn+1;
			while(1){
				y=y-(i+2*fn);
				//cout<<i<<" "<<fn<<" "<<y<<endl;
				if(y<=0){
					break;
				}
				i++;
			}
			cout<<i+2<<endl;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		bool flag=0;
		for(int j=i+1;j<=n;j++){
			long long op=a[j],sum=0;
			for(int k=i;k<j;k++){
				sum+=(op-a[k]);
				//cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<" "<<sum<<endl;
				if(sum>m){
					flag=1;
					break;
				}
			}
			if(!flag){
				long long k=j-i+1;
				ans=max(k,ans);
			}
			else{
				break;
			}
		}	
	}
	cout<<ans;
	return 0;
}

