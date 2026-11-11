#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],to[205];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		sort(a+1,a+1+n);
		int mx=0;
		for(int i=1;i<=n;i++){
			int t=a[i],cnt=0,num=0;
			for(int j=i-1;j>=1;j--){
				if(cnt+(t-a[j])<=m){
					cnt+=(t-a[j]);
					num++;
				}
				else break;
			}
			//cout<<t<<' '<<cnt<<' '<<num+1<<'\n';
			mx=max(mx,num+1);
		}
		cout<<mx;
		return 0;
	}
	bool flag=0;
	for(int i=2;i<n;i++){
		if(a[i+1]-a[i]!=a[i]-a[i-1]){
			flag=1;
			break;
		}
	}
	if(!flag){
		int num=0,cnt=1,ans=1,k=a[2]-a[1];
		cnt*=k;
		for(int i=2;i<=n;i++){
			if(num+cnt<=m){
				num+=cnt;
				cnt+=k;
				ans++;
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	//bool flag=0;
	for(int i=1;i<=n;i++){
		if(a[i]<-100||a[i]>100){
			flag=1;
			break;
		}
		else{
			a[i]+=101;
			to[a[i]]++;
		}
	}
	//for(int i=0;i<=200;i++) cout<<i<<":"<<to[i]<<'\n';
	if(!flag){
		int cnt=0,k=0,jbef=0,ibef=0;
		int i=0,j=0,num=0,mx=0;
		while(j<=201&&i<=201){
			if(cnt+k<=m){
				j++;
				cnt+=k;
				k+=to[j];
				jbef=j;
				num+=to[j];
				mx=max(mx,num);
			}
			else{
				ibef=i;
				while(to[i+1]==0&&i+1<=200&&i+1<=j) num-=to[i],i++;
				num-=to[i],i++;
				k-=to[ibef];
				cnt-=(jbef-ibef)*to[ibef];
				mx=max(mx,num);
			}
			//printf("cnt:%d k:%d jbef:%d ibef:%d i:%d j:%d num:%d mx:%d\n",cnt,k,jbef,ibef,i,j,num,mx);
		}
		cout<<mx;
	}
	return 0;
}
/*
11 5
1 1 3 4 4 5 5 5 7 7 9
*/