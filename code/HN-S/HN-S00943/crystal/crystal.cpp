#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	int mx=-1,last=-9999999,sum=0;
	for(int i=1;i<=n;i++){
		mx=max(sum,mx);
		if(last==a[i]){
			sum++;
			continue;
		}
		int t=m;
		sum=0;
		for(int j=i;j>=1;j--){
			int b=a[i]-a[j];
			if(b<=t){
				sum++;
				t-=b;
			}else{
				break;
			}
		}
		last=a[i];
	}
	cout<<mx;
	return 0;
}
