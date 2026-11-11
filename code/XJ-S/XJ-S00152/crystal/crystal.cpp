#include<bits/stdc++.h>
using namespace std;
int a[500005];
int sum[500005];
int s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		int mx=0;
		int t=i;
		s[i]=1;
		while(t--){
			sum[t]=a[i]-a[t];
			if(mx+sum[t]<=m){
				mx+=sum[t];
				s[i]++;
			}else{
				break;
			}
		}
	}
	sort(s+2,s+n+1);
	cout<<s[n];
	return 0;
}
