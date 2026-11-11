#include<bits/stdc++.h>
using namespace std;
long long arr[500005];
long long arr2[500005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt=1,maxc=1;
	cin>>n>>m;
	int m2=m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n,cmp);
	for(int i=0;i<maxc;i++){
		for(int j=0;j<n;j++){
			arr2[j]=arr[j];
		}
		cnt=1,m2=m;
		int g=0;
		for(int j=i+1;j<n;j++){
			if(arr2[i]-arr2[j]<=m2){
				m2=m2-arr2[i]+arr2[j];
				arr2[j]=arr2[i];
				cnt++;
				if(m2==0){
					break;
				}
			}else{
				break;
			}
		}
		maxc=max(maxc,cnt);
	}
	cout<<maxc;
	return 0;
} 
