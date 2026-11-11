#include<bits/stdc++.h>
#define ll long long
#define sc scanf
#define pf printf
using namespace std;
int n,ans,minx=1,cnt;
ll m,a[500005],pre[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	sc("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		sc("%lld",&a[i]);
		if(a[i]<0){
			if(minx>a[i])minx=0-a[i];
		}
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]+=minx;
		pre[i]=a[i]-pre[i-1];
		cnt+=pre[i];
	}
	
	int l=cnt/n,r=l;
	m-=pre[l];
	pre[l]=0;
	while(m){
		if(pre[l-1]>pre[r+1]){
			if(pre[r+1]==0){
				if(m>=pre[l-1]){
				m=m-pre[l-1];	
				pre[l-1]=0;
				l--;
				ans++;
				
			}
			else break;
		}
			if(m>=pre[r+1]){
				m=m-pre[r+1];	
				pre[r+1]=0;
				r++;
				ans++;
				
			}
			else break;
		}
		else{
			if(pre[l-1]==0){
				if(m>=pre[r+1]){
				m=m-pre[r+1];	
				pre[r+1]=0;
				r++;
				ans++;
				
			}
			else break;
			}
			if(m>=pre[l-1]){
				m=m-pre[l-1];	
				pre[l-1]=0;
				l--;
				ans++;
				
			}
			else break;
		}
	}
	pf("%d",ans);
	return 0;
} 
