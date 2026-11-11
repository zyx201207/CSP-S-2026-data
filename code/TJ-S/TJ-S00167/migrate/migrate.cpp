#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long arr[2000005]={};
bool arr1[2000005]={};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(arr,0,n+1);
		memset(arr1,0,n+1);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		for(int i=0;i<n-3;i++){
			if(arr[i+2]-arr[i]<=d&&arr[i+3]-arr[i+1]<=d&&arr[i+3]-arr[i]>d)arr1[i]=true;
		}
		int sum=0;
		for(int i=0;i<n-3;i++){
			int cnt=0;
			if(arr[i+1]-arr[i]>d||arr[i+2]-arr[i+1]>d)continue;
			for(int j=i+3;j<n;j++){
				if(arr[j]-arr[j-1]>d)break;
				if(arr1[j-3]){
					cnt++;
				}
				if(cnt==1)sum++;
				if(cnt>1)break;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}


