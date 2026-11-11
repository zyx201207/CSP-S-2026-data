#include<bits/stdc++.h>
using namespace std;
	int a[500001];
	int main(){
		freopen("crystal.in","r",stdin);
		freopen("craystal.out","w",stdout);
		int n;
		long long m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		int c=1;
		for(int i=1;i<=n;i++){
			int d=i,sum=0,cnt=0;
			while(d==1&&sum<=m){
				if(a[i]-a[d]+sum>m){
					break;
				}
				else{
					sum+=a[i]-a[d];
					cnt++;
					d--;
				}
			}
			c=max(c,cnt);
		}
		cout<<c;
		return 0;
	}
