#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	ll arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n+1,cmp);
	for(int i=0;i<m-1;i++){
		arr[i+1]=arr[i]&arr[i+1];
	} 
	cout<<arr[m];
	return 0;
	
}
