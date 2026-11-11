#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int a[N];
int ejz[N][33],pw[33];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=31,j=0;i>=1;--i,++j) pw[i]=pow(2,j);
	int n,m,ct=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	stable_sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;++i){
		int j=31,x=0;
		while(a[i]>0){
			ejz[i][j]=a[i]%2;
			a[i]/=2;
			j--,x++;
		}
		ct=max(ct,x);
	}
	int pre=n,sum=0;
	for(int i=32-ct;i<=31;++i){
		int lo=1,hi=pre;
		while(lo<=hi){
			int mid=(lo+hi)/2;
			if(ejz[mid][i]==1) lo=mid+1;
			else hi=mid-1;
		}
		lo--;
		if(lo>=m) pre=lo,sum+=pw[i];
		else{
			for(int j=1;j<=pre;++j){
				a[j]=0;
				for(int k=i+1;k<=31;++k){
					a[j]+=ejz[j][k]*pw[k];
				}
			}
			stable_sort(a+1,a+pre+1,greater<int>());
			for(int j=1;j<=pre;++j){
				for(int k=1;k<=31;++k) ejz[j][k]=0;
				int k=31;
				while(a[j]>0){
					ejz[j][k]=a[j]%2;
					a[j]/=2;
					k--;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
