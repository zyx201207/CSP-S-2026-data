#include<bits/stdc++.h>
using namespace std;
int a[100005]={0};
int sum[100005];
int n,d;
int main(){
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(i==j)continue;
				if(abs(a[i]-a[j])>d){
					continue;
				}
				for(int k=i+1;k<=j-1;k++){
					if(a[k]-a[i]==a[j]-a[k]){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
