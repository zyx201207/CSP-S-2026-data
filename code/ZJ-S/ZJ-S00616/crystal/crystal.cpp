#include <bits/stdc++.h>
using namespace std;
long long n,m,sum,cnt,ma=0,miji=1e6,maji=-1e6;
long long a[500010],ji[200010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ji[a[i]+100000]++;
		miji=min(miji,a[i]);
		maji=max(maji,a[i]);
	}
	for(int i=miji+100000;i<=maji+100000;i++){
		if(ji[i]==0) continue;
		cnt=m,sum=ji[i];
		for(int j=i-1;j>=miji+100000;j--){
			if(ji[j]==0) continue;
			sum+=ji[j];
			cnt-=(i-j)*ji[j];
			if(cnt<0){
				sum-=ji[j];
				cnt+=(i-j)*ji[j];
				sum+=cnt/(i-j);
				break;
			}
		}
		ma=max(ma,sum);	
	}
	cout<<ma;
	return 0;
}