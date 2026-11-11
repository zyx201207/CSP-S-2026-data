#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500005],maxx=-0x3f3f3f3f,cnt;	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int num=m;
		cnt=0;
		for(int j=i+1;j<=n;j++){
			if(a[j]==a[i]){
				cnt++;
			}
		}
		for(int j=i;j>=1;j--){
			if(num-(a[i]-a[j])>=0){
				num-=(a[i]-a[j]);
				cnt++;
			}
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
} 
