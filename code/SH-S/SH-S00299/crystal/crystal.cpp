#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,m;
int s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int _max=0;
	for(int i=1;i<=n;i++){
		int l=1;
		int r=i;
		//yi di i ge wei jie wei
		while(l<=r){
			int mid=(l+r)/2;
			int Len=i-mid+1;
			if(a[i]*Len-(s[i]-s[mid-1])<=m){
				_max=max(_max,Len);
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	cout<<_max<<endl;
	return 0;
} 
