#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
const int N=500005;
int n,a[N],t[N][N],b[N],ans=0,c[N],comax=0;
long long m;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++）{
		cin>>a[i];
	};
	for(int i=1;i<=n;i++){
		sort(a[i]+1,a[i]+n+1,cmp);
	};
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			t[i][j]=a[j]-a[i];
			if(t[i][j]>m)break;
		};
	};
	for(int j=2;j<=n;j++){
		for(int i=1;i<=n;i++){
			if(i<=j){
			ans=ans+t[i][j];
			b[j]=ans;
			c[j]++;
			};
		};
		if(b[j]>m)break;
		else{
			if(c[j]>=c[j+1])comax=c[j];
			if(c[j]<c[j+1])comax=c[j+1];
		};
	};
	cout<<comax;
	return 0;
}
