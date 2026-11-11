#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std;
int a[500005],s[500005];
long long n,m;
bool flag=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	int p;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i==2)p=a[2]-a[1];
		if((a[i]-a[i-1])!=p&&i>2)flag=false;
	}
	sort(a+1,a+n+1);
	if(a[1]<0){
		int q=0-a[1];
		for(int i=1;i<=n;i++)a[i]+=q;
	}
	if(flag==true){
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+i;
			if(p*s[i-1]>m){
				cout<<i-1;
				return 0;
			}
		}
	}
	int v=0,ans=0,maxn=0;
	for(int i=1;i<=n;i++){
		ans=1,v=0;
		for(int j=i-1;j>=1;j--){
			v+=a[i]-a[j];
			if(v<=m)ans++;
			else break;
		}
		if(ans>maxn)maxn=ans;
	}
	cout<<maxn;
	return 0;
} 