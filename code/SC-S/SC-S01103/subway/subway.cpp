#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c[500010];
int main(){
	//freopen("crystal4.in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i];
	}
	int t=1;
	long long sum=(t-1)*c[t];
	while(sum<m||c[t]==c[t+1]){
		t++;
		int i=t-1;
		sum=(t-1)*c[t];
		for(i;i>0;i--)sum-=c[i];
	}
	int h=1;
	while(sum>m){
		sum-=(c[t]-c[h]);
		h++;
	}
	cout<<t-h+1;
	return 0;
}