#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans,sum=0,num=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;++i){
		cin >>a[i];
	}
	sort(a,a+n);
	int cnt;
	for(cnt=n-2;cnt>=0;--cnt){
		if(sum+a[n-1]-a[cnt]<=m){
			sum+=(a[n-1]-a[cnt]);
			num++;
		}
		else break;
	}
	ans=num;
	int j=cnt;
	for(int i=n-1;i>0&&cnt>=0;--i){
		sum-=((a[i]-a[i-1])*num);
		num--;
		for(;j>=0;--j){
			if(sum+a[i-1]-a[j]<=m){
				sum+=(a[i-1]-a[j]);
				num++;
			}
			else break;
		}
		if(num>=ans){
			ans=num;
			cnt=j;
		}
	}
	cout << ans+1;
	return 0;
}