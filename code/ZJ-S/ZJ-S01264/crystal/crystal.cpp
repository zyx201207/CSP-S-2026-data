#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,maxn;
long long a[500005],b[500005];
bool cmp(long long aa,long long bb){
	return aa<bb;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	b[1]=0;
	for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
	long long count=0;
	for(int i=1;i<=n;i++){
		count+=b[i]*ans;
		if(count<=m){
			ans++;
			if(ans>maxn) maxn=ans;
		}else{
			count-=a[i]-a[i-ans];
			while(count>m){
				ans--;
				count-=a[i]-a[i-ans];
				
			}
		}
	}
	cout<<maxn;
	return 0;
}
