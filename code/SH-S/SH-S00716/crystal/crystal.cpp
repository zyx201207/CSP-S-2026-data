#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=1;
long long a[50000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<m;i++){
		sort(a,a+n);
		a[0]++;
		long long x=1;
		for(long long j=0;j<n;j++){
			if(a[j]==a[j+1]){
				x++;
			}
			else{
				break;
			}
		}
		cnt=max(cnt,x);
	}
	cout<<cnt;
	return 0;
} 
