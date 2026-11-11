#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=0,sum,s;
bool is[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
			s=i;
		}
		sum=sum&a[i];
		if(i==1) sum=a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<sum;
		return 0;
	}
	if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
