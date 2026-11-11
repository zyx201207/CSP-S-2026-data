#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long ans;
long long a[500001]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i<=2){
			continue;
		}
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag=false;
		}
	}
	if(flag){
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=i;
			if(sum>m){
				break;
			}
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	if(n>5000){
		int l=1;
		long long temp=0,sum=0;
		for(int j=l+1;j<n;j++){//end
			sum+=(j-l+1)*(a[j+1]-a[j]);
			while(sum>m && l<=j){
				sum-=(a[j+1]-a[l]);
				l++;
				temp--;
			}
			temp++;
			ans=max(temp+1,ans);
		}
		cout<<ans+1;
		return 0;
	}
	for(int i=1;i<=n;i++){//start
		long long temp=0,sum=0;
		for(int j=i;j<=n;j++){//end
			sum+=(j-i+1)*(a[j+1]-a[j]);
			if(sum>m){
				break;
			}
			temp++;
		}
		ans=max(temp+1,ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
