#include <bits/stdc++.h>
using namespace std;
//zcy
#define int long long
const int N=500010;
int n,m;
int zcy=1;
int a[N],cf[N]; //a2-a1,a3-a2
__int128 l[N];//a1+2a2+3a3
__int128 qz[N];//a1+a2+a3
bool pd(int i,int j){
	__int128 num=l[j]-l[i-1]-(i-1)*(qz[j]-qz[i-1]);
	if(num<=m) return true;
	else return false;
	}
signed main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	}
sort(a+1,a+n+1);
for(int i=1;i<n;i++){
	cf[i]=a[i+1]-a[i];
	if(cf[i]<=m) zcy=2;
	l[i]=l[i-1]+i*cf[i];
	qz[i]=qz[i-1]+cf[i];
	}
for(int i=1;i<n;i++){
	int k=1,j=i,mid;
	while(k<=j){
		mid=(k+j)/2;
		if(pd(mid,i)){
			zcy=max(i-mid+2,zcy);
			j=mid-1;
			}
		else
			k=mid+1;
		}
	}
cout<<zcy;
return 0;
}
//15:11zuowan
