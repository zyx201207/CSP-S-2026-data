#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,ans,i,a[2000010],p,t,w,bao,mid,nxt[2000010],dp[20010][200],j,l,k,
bj[200010],lst,pre[2000010],qz[20010][200];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++){
			p=a[i]+d;
			t=i;w=n;bao=i;
			while(t<=w){
				mid=(t+w)/2;
				if(a[mid]<=p) bao=mid,t=mid+1;
				else w=mid-1;
			}
			nxt[i]=bao;
		}
		for(i=1;i<=n;i++){
			p=a[i]-d;
			t=1;w=i;bao=i;
			while(t<=w){
				mid=(t+w)/2;
				if(a[mid]>=p) bao=mid,w=mid-1;
				else t=mid+1;
			}
			pre[i]=bao;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				for(l=0;l<=n;l++) dp[j][l]=qz[j][l]=0;
			dp[i][0]=1;qz[i][0]=1;
			for(j=i+1;j<=n;j++){
				for(l=1;l<=n;l++)
					dp[j][l]+=qz[j-1][l-1]-qz[pre[j]-1][l-1];
				for(l=0;l<=n;l++) qz[j][l]=qz[j-1][l]+dp[j][l];
			}
			for(j=1;j<=n;j++) bj[j]=0;l=0;
			p=i;bj[i]=0;while(p<n&&p!=nxt[p]) p=nxt[p],l++,bj[p]=l;
			for(j=n;j>=i;j--)
				if(bj[j]!=0) lst=bj[j];
				else bj[j]=lst;
			for(j=i;j<=n;j++)
				if(dp[j][bj[j]]==2) ans++;
		}
		cout<<ans<<"\n";
		/*
		for(i=1;i<=n;i++){
			if(nxt[i]==i) continue;p=nxt[i];
			ans=ans+nxt[p-1]-nxt[p-2];
			if(nxt[p-1]==nxt[p-2]) continue;
	//		if(nxt[p-2]==p) ans--;
			while(p<=n){
				cout<<p<<" ";
				if(nxt[p]==p) break;
				p=nxt[p];ans=ans+nxt[p]-nxt[p-1];
				if(nxt[p]==nxt[p-1]) continue;
	//			if(nxt[p-1]==p) ans--;
			}
		}
		cout<<ans<<"\n";*/
	}
}