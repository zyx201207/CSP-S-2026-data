#include<bits/stdc++.h>
using namespace std;
long long n,m,a[514514],maxn=-114514114514,dq=0,cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long i=1,j=0;
	while(j<n){
		j++;
		dq+=a[j];
		cnt++;
		if(a[j]*cnt-dq>m){
			while(a[j]*cnt-dq>m){
				cnt--;
				dq-=a[i];
				i++;
			}
		}
		maxn=max(maxn,cnt);
	}
	cout<<maxn;
	return 0;
}
