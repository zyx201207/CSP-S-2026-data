#include<bits/stdc++.h>
using namespace std;
    long long n,m,a[500005],maxn,ans,dat,cnt;
	void find(int l,int r,long long len,int left,int mid){
		if(left==0){
			maxn=max(maxn,len);
			return;
		}
		if(a[l-1]<=mid&&left-(mid-a[l-1])>=0&&l-1>=1){
			find(l-1,r,len+1,left-(mid-a[l-1]),mid);
		}
		if(a[r+1]<=mid&&left-(mid-a[r+1])>=0&&r+1<=n){
			find(l,r+1,len+1,left-(mid-a[r+1]),mid);
		}
		if(a[l-1]>mid&&a[r+1]>mid){
			find(l,r,len,0,mid);
		}
	}
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dat=a[2]-a[1];
	bool flag=0;ans=0;cnt=0;
	for(int i=3;i<=n;i++){
		if(a[i]-dat!=a[i-1]){
			flag=1;
		}
	}
	if(flag==0){
		for(int i=1;i<=n;i++){
			if(m-i>=0){
				cnt+=dat;
				m-=cnt;
				ans++;
			}
			else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	maxn=-1;
	for(int i=1;i<=n;i++){
		find(i,i,1,m,a[i]);
	}
	cout<<maxn;
	
}