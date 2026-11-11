#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],maxans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxans=max(maxans,a[i]);
	}
	if(m==1){
		cout<<maxans;
		return 0;
	}maxans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long t=(a[i]&a[j]);
			maxans=max(maxans,t);
		}
	}
	cout<<maxans;
	return 0;
}

