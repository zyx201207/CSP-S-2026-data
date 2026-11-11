#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;cin>>n;
	long long m;cin>>m;
	if(n<=0){
		int a[5009];
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+1+n);
		int Max=0;
		for(int i=1;i<=n;i++){
			int now=0,cnt=1;
			for(int j=i-1;j>=1;j--){
				now+=(a[i]-a[j]);
				if(now<=m) cnt++;
				else break;
			}
			Max=max(Max,cnt);
		}
		cout<<Max<<endl;
	}else{
		long long a[500009];
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(abs(a[i])>100) flag1=0;
			if(a[i]!=i) flag2=0;
		}
		if(flag1){
			int cnt[205],Max=0;
			for(int i=1;i<=n;i++)
				cnt[a[i]+101]++;
			for(int i=1;i<=201;i++){
				int used=0,c=cnt[i];
				for(int j=i-1;j>=1;j--){
					int can=(m-used)/(i-j);
					c+=min(cnt[j],can);
					used+=min(cnt[j],can)*(i-j);
					if(m-used<=i-j) break;
				} 
				Max=max(Max,c);
			}
			cout<<Max<<endl;
		}else if(flag2){
			int now=1;
			while(m<=(now+1)*now/2)
				now++;
			cout<<min(now-1,n)<<endl;
		}else{
			int now=1;
			while(m<=(now+1)*now*(a[2]-a[1])/2)
				now++;
			cout<<min(now-1,n)<<endl;
		}
	}
	return 0;
}
