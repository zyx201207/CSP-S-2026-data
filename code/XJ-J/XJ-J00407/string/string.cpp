#include<bits/stdc++.h>
using namespace std;
long long arr[200005];
char a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	long long n,cnt=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>a[i];
		cnt+=arr[i];
	}
	int i=1,j=n;
	long long x=0;
	while(i<=j){
		if(a[i]!=a[j]){
			ans+=min(arr[i],arr[j]);
		}
		x=min(arr[i],arr[j]);
		if(i==j){
			arr[i]-=x;
		}
		else{
			arr[i]-=x;
			arr[j]-=x;	
		}
		if(arr[i]==0)i++;
		if(arr[j]==0)j--;
	}
	cout<<ans<<'\n';
}
