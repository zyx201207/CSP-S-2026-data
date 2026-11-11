#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt,sum[500005],lst[300005],nxt[500005],c[500005],res1[500005],res2[300005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) b[++cnt]=a[i];
	}
	for(int i=cnt;i>=1;i--){
		if(lst[b[i]]==0) lst[b[i]]=i;
		if(c[b[i]]) nxt[i]=c[b[i]];
		c[b[i]]=i;
	}
	for(int i=1;i<=cnt;i++) sum[i]=sum[i-1]+nxt[i];
	for(int i=1;i<=cnt;i++){
		for(int j=i;j<=cnt;){
			if(nxt[j]) j=lst[b[j]];
		//	cout<<j<<" ";
			if(sum[cnt]-sum[j]==0){
				res1[j]++;
				break;
			}else{
				int l=j+1,r=cnt,mid,ans;
				while(l<=r){
					int mid=l+r>>1;
					if(sum[mid]-sum[j]>0) ans=mid,r=mid-1;
					else l=mid+1;
				}
				res1[j]++;res1[ans]--;j=ans;
			}
		}
	}
	for(int i=1;i<=cnt;i++) res1[i]+=res1[i-1];
	for(int i=1;i<=cnt;i++) res2[b[i]]+=res1[i];
	for(int i=1;i<=m;i++) cout<<res2[i]<<" ";
	return 0;
}
//
