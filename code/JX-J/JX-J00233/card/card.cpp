#include <bits/stdc++.h>
using namespace std;
//zcy
const int N=500010,M=300010;
int n,m;
bool f[M]; 
bool pd[M];
int wz[N];
int a[N];
int cnt;
bool flag=1;
int zcy[M];
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
for(int i=n;i>=1;i--){
	cin>>a[i];
	if(a[i+1]>a[i]) flag=0;
	}
for(int i=1;i<=n;i++){
	if(f[a[i]]==1){
		wz[++cnt]=i;
		if(cnt==1){
			for(int j=1;j<i;j++)
				if(a[j]==a[i]) {
					wz[0]=j+1;
					break;
					}
			}
		}
	else
		f[a[i]]=1;
	}
for(int i=1;i<wz[0];i++){
	zcy[a[i]]=n-i+1;
	pd[a[i]]=1;
	}
wz[cnt+1]=n+1;
for(int i=0;i<=cnt;i++){
	for(int j=wz[i];j<wz[i+1];j++){
		if(pd[a[j]]==0)
			zcy[a[j]]+=(wz[i+1]-j);
		}
	}
for(int i=1;i<=m;i++)
	cout<<zcy[i]<<" ";
return 0;
}
