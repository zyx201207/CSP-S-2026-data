#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2000010];
int minstep[2000010];
int ans[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int T=0;T<t;T++){
		int n,d;
		cin>>n>>d;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int k=1;k<=n;k++){
			memset(minstep,0,sizeof(minstep));
			memset(ans,0,sizeof(ans));
			ans[k]=1;
			for(int i=k+1;i<=n;i++){
				int mind=INT_MAX;
				for(int j=i-1;j>=k&&a[i]-a[j]<=d;j--){
					mind=min(mind,minstep[j]);
				}
				minstep[i]=mind+1;
				for(int j=i-1;j>=k&&a[i]-a[j]<=d;j--){
					if(minstep[j]==mind){
						ans[i]+=ans[j];
					}
				}
			}
			
//			for(int i=k;i<=n;i++){
//				cout<<ans[i]<<" ";
//			}
//			cout<<"\n";
			for(int i=k;i<=n;i++){
				if(ans[i]==2){
					sum++;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5

*/
