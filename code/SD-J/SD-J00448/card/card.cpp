#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[300010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long arr[n+2];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		stack<int> desk;
		desk.push(arr[i]);
		for(int j=i+1;j<=n;j++){
			if(!desk.empty()&&desk.top()>arr[j]){
				while(!desk.empty()&&desk.top()>arr[j]){
					desk.pop();
				}
			}
			else {
				desk.push(arr[j]);
			}
		}
		for(int j=1;j<=m;j++){
			if(desk.top()>j)a[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
