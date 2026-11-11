#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int arr[N];
int brr[N];
int crr[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=n;i>=1;i--){
		if(brr[arr[i]]==0){
			brr[arr[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		crr[i]=brr[arr[i]];
	}
	for(int i=1;i<=n;i++){
		int x=i;
		while(x!=n+1){
			ans[arr[x]]++;
			x=crr[x]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
