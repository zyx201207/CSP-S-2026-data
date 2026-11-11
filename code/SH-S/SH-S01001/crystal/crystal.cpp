#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],nowm,sum[500005],ans[500005],start,maxn,cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		sum[i]=a[i]-a[i-1];
		ans[i]=ans[i-1]+sum[i];
	}
	sum[0]=0;
	ans[0]=ans[1]=0;
	nowm=m;
	start=0;
	for(int i=1;i<=n;i++){
		if(m<sum[i]){//此路不同 
			maxn=max(maxn,cnt);
			cnt=0;
			start=i;
			nowm=m;
		}
		else if(m>=ans[i]-ans[start]){
			if(nowm-(ans[i]-ans[start])>=0){//我可以走 
				cnt++;
				nowm-=(ans[i]-ans[start]);
				maxn=max(maxn,cnt);
			}
			else if(nowm<ans[i]-ans[start]){//可以走但是要改变起点 
				while(nowm<=ans[i]-ans[start]){
					cnt=0;
					nowm+=(ans[i]-ans[start]);
					start++;
				}
				cnt++;
				nowm-=(ans[i]-ans[start]);
				maxn=max(maxn,cnt);
			}
		}
	}
	cout<<maxn<<endl;
}
