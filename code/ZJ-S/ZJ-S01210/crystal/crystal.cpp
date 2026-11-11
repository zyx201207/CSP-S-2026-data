#include<bits/stdc++.h>
using namespace std;
long long n,cnt=1,sum=0,ans=0,aaa=1;
long long m,k;
long long arr[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	
	bool flag=1;
	for(int i=2;i<=n/2;i++){
		if(arr[i]-arr[i-1]==arr[i+1]-arr[i]){
			continue;
		}
		else{
			flag=0;
			break;
		}
	}
	if(flag==1){
		k=arr[2]-arr[1];
		for(int i=1;i<=n;i++){
			if((k+k*i)*i/2>m){
				aaa=i;
				break;
			}
		}
		cout<<aaa;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		sum=0;cnt=1;
		for(int j=i-1;j>0;j--){
			if(abs(arr[i]-arr[j])+sum<=m){
				cnt++;
				sum+=abs(arr[i]-arr[j]);
			}
			else{
				break;
			}
		}
		if(cnt>ans)ans=cnt;
	}
	cout<<ans;
	return 0;
}
