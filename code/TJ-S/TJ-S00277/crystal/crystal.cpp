#include<bits/stdc++.h>
using namespace std;
long long arr[500001],ans[500001]={0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	long long MX=0;
	for(int i=2;i<n;i++){
		long long mm=m;
	    for(int j=i;j>1;j--){
	    	if(mm-(arr[i]-arr[j-1])>=0){
	    		mm-=(arr[i]-arr[j-1]);
	    		ans[i]++;
			}
			else {
				break;
			}
		}
		if(ans[i]>MX){
			MX=ans[i];
		}
	}
    cout<<MX+1; 
	return 0;
}
