#include <bits/stdc++.h>
using namespace std;
int x[2000005];
int qianxi(int n,int d){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;i<=n;i++){
			int sum=0,num=0;
			if(x[j]-x[i]<=d){
				continue;
			}
			int k1=j,num1=2000001;
			for(int k=j;k<=i;k++){
				if(x[k]-x[k1]>d&&k-1<=k1){
					break;
				}else if(x[k]-x[k1]>d){
					k1=k-1;
					num1++;
				}else if(x[k]-x[k1]==d){
					k1=k;
					num1++;
				}
				if(num<=num1){
					sum++;
				}else{
					num=num1;
					sum=0;
				}
			}
			if(sum==2){
				ans++;
			}
		}
	}
	return ans;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cout<<qianxi(n,d)<<"\n";
	}
	return 0;
}
