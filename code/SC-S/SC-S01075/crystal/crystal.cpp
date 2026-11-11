#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,h,t,a[500005],sum[500005],cnt[500005],ans=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		y++,cnt[t]++;
		if(a[i]==a[i+1]) continue;
		while(x>m){
			if((a[i]-sum[h])*cnt[h]>x-m){
				long long l=1,r=cnt[h];
				while(l<r){
					long long mid=(l+r)/2;
					if(mid*(a[i]-sum[h])>x-m) r=mid;
					else l=mid+1;
				}
				y-=l,cnt[h]-=l;
				x-=l*(a[i]-sum[h]);
			}
			else{
				y-=cnt[h],x-=(a[i]-sum[h])*cnt[h];
				h++;
			}
		}
		ans=max(ans,y);
		sum[t]=a[i],x+=(a[i+1]-sum[t])*y;
		t++;
	}
	cout<<ans;
	
	return 0;
}
/*

zan mei yu zhe
yuan shang wu qi qiu de hao yun yu wo tong zai

*/

/* er deng yao xiang xin ping ce ji , ta hui dai ling ru zhi chang shu zou xiang ac */