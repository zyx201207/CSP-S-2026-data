#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,m,ans=1;
long long a[N];
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl<<endl<<endl; 
	long long sum=1,mm=m;
	int k=1;
	bool flag=true;
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]<=m){
			if(flag){
				if((a[i+1]-a[i])*(sum-1)<=a[i]-a[k]&&mm-(a[i+1]-a[i])*sum<0){
					mm+=a[i]-a[k];
					k++;
					sum--;
					mm-=(a[i+1]-a[i])*sum;
					sum++;
				}
				if(mm-(a[i+1]-a[i])*sum>=0){
					mm-=(a[i+1]-a[i])*sum;
					sum++;
				}else{
					if((a[i+1]-a[i])*(sum-1)<=a[i]-a[k]){
						mm+=a[i]-a[k];
						k++;
						sum--;
						mm-=(a[i+1]-a[i])*sum;
						sum++;
					}
					else {
						flag=false;
						//cout<<a[i]<<endl;
					}
				}
			}
		}else{
			ans=max(ans,sum);
			sum=1;
			k=i+1;
			mm=m;
			flag=true;
		}
	}
	//cout<<k<<endl;
	ans=max(ans,sum);
	cout<<ans<<endl;
	return 0;
}
