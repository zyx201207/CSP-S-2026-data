#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int Max=-1,x=m;
	for(int i=1;i<=n;i++){
		int ans=0,ii=i;
		while(x!=0&&ii!=0){
			x-=a[i]-a[ii];
			if(x>0){
				ans++;
				ii--;
			} 
			if(x==0){
				ans++;
				break;
			}
		}
		Max=max(Max,ans);
	}
	cout<<Max;
	return 0;
} 
//5 5
//2 1 2 4 8 