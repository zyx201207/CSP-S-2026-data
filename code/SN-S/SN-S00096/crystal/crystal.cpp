#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define int long long
using namespace std;
int n,m;
int maxn=0;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int _m=m;int cnt=1;
	sort(a+1,a+n+1);
	for(int j=1;j<=n;j++){
		int k=a[j];
		
		for(int i=1;i<=n;i++){
			if(a[i]<k){
				_m-=(k-a[i]);
				if(_m<0){
					maxn=max(maxn,cnt);
					_m=m;
					break;
				}
				cnt++;
			}
			else if(a[i]==k&&i!=j){
				cnt++;
			}
			else{
				maxn=max(maxn,cnt);
				cnt=1;
				_m=m;
				break;
			}
		}
	}
	cout<<maxn;
	return 0;
} 
