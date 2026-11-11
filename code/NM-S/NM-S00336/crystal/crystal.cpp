#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[5150],ans=0,w[5010],b[5010],sasa=-1e6;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=0;
		cin>>a[i];
		w[i]=0;
	}
	sort(a+1,a+1+n);w[1]=1;
	for(int i=n;i>0;i--){
		ans=0;
		for(int j=i-1;j>0;j--){
			b[j]=a[i]-a[j];
			if(b[j]>m) break;
			ans+=b[j];
			if(ans>m) break;
			w[i]++;
		}
		sasa=max(w[i],sasa);
	}
	cout<<sasa+1;
	return 0;
}
