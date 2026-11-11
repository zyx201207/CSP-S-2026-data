#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],b[100000],c[100000],d[100000],cnt,cntt,sum;
int two(int x,int y){
	cnt=cntt=0;
	while(x!=0){
		b[++cnt]=x%2;
		x/=2;
	}
	while(y!=0){
		c[++cntt]=x%2;
		x/=2;
	}
	cnt=max(cnt,cntt);
	for(int i=1;i<=cnt;i++){
		if(a[i]==1&&b[i]==1){
			d[i]=1;
			cntt=i;
		}
		else{
			d[i]=0;
		}
	}
	for(int i=1,j=cntt;i<=cntt,j>=1;i++,j--){
		b[i]=d[j];
	}
	for(int i=0,j=cntt;i<=cntt-1,j>=1;i++,j--){
		sum+=pow(b[j],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum=a[1];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	for(int i=2;i<=n;i++){
		two(sum,a[i]);
	}
	cout<<sum;
	return 0;
}
