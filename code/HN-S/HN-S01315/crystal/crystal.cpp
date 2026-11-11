#include<bits/stdc++.h>
using namespace std;
struct node{
	long long t,h;
}a[50000005];
long long n,m,maxn=LLONG_MIN;
bool cmp(node x,node y){
	return x.h<y.h;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long sum;
	for(int i=1;i<=n;i++){
		cin>>a[i].t;
	}
	for(int j=1;j<=n;j++){
		sum=a[j].t;
		for(int i=1;i<=n;i++){
			a[i].h=abs(sum-a[i].t);
		}
		sort(a+1,a+n+1,cmp);
		long long s=0,ans=0;
		for(int i=1;i<=n;i++){
			if(s+a[i].h>m){
				break;
			}
			s+=a[i].h;
			ans++;
		}
		maxn=max(maxn,ans);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
