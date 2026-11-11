#include<bits/stdc++.h>
using namespace std;
long long a[200001];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		long long x=a[i],y=0;
		int j=0;
		while(x!=0){
			y+=pow(10,j)*(x%2);
			j++;
			x/=2;
		}
		a[i]=y;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		int x=a[i];
		int sum=0,j=0;
		while(x!=0){
			sum+=x%10*pow(2,j);
			j++;
			x/=10;
		}
		a[i]=sum;
		cout<<a[i]<<' ';
	}
	int mx=a[1];
	for(int i=1;i<=m;i++){
		mx=mx&a[i];
	}
	cout<<mx;
	return 0;
}