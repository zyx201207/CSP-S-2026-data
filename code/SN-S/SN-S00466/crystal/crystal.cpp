//姜承宇 SN-S00466 西安翱翔中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum = 0,mid = 0;
bool cmp(int x,int y){
	return x-mid<y-mid;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int x = lower_bound(a+1,a+n+1,sum/n)-a;
	mid = a[x];
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i<=n;i++){
		if(a[i]!=mid){
			if(mid-a[i]>m or mid-a[i]<0){
				break;
			}else{
				m-=abs(a[i]-mid);
				a[i] = mid;
			}
		}
	}
	int cnt = 0;
	for(int i = 1;i<=n;i++){
		if(a[i] == mid){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
