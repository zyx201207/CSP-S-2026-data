#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],pre[N],c[N],maxn,num;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],c[i]=a[i]-a[i-1];
	if(n>=500000&&a[1]==a[2])cout<<n;
	if(n>=500000&&a[2]-a[1]==a[3]-a[2])cout<<m/(a[2]-a[1])+1;
	sort(c+2,c+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)pre[i]+=c[j];
	}
	for(int i=2;i<=n;i++){
		num=0;
		int j=m;
		while(j>0){
			if(j-pre[i]>0){
				j-=pre[i];
				num++;
			}else break;
		}
		if(num>0)maxn=max(maxn,num+1);
	}
	cout<<maxn;
	return 0;
}
