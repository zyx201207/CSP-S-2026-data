#include<bits/stdc++.h>
using namespace std;
int m,ans,n,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<bool>bl(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bl[i]=1;
	}
	for(int i=30;i>=0;i--){
		int sum=0;
		vector<bool>b(n+1);
		for(int j=1;j<=n;j++){
			if(bl[j]==1){
			if(a[j]&(1<<i)){
		//		cout<<a[j]<<" "<<(1<<i)<<" "<<(a[j]&(1<<i))<<"\n";
				sum++;
				b[j]=1;
			}
		}
		}
		if(sum>=m){
			ans+=(1<<i);
			bl=b;
		}
	}
	cout<<ans;
	return 0;
} 
