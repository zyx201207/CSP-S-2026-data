#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int INF=1e8+5;
ll n,m,cnt;//3 4 3845
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		ll mii=n+1;
		a[n+1]=INF;
		for(int j=i;j<n;j++){
			if(a[j]<a[mii])mii=j;
		}
		ll l=a[i];
		a[i]=a[mii];
		a[mii]=l;
		
	}
	for(int i=0;i<n;i++){
		ll ma=1; 
		ll m2=m;//ÈÝÁ¿ 
		for(int j=i-1;j>=0;j--){
			m2=m2-(a[i]-a[j]);
			if(m2<0)break;
			else ma++;
		}
		if(cnt<ma)cnt=ma;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
