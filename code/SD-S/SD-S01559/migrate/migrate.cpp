//3xin
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
using namespace std;
mt19937_64 rd(time(0));
const int N=2e6+5;
int n,c,t,mn[N],R[N],L[N],kuai[N],sum[N],d,a[N],mx[N],kl[N],sum2[N],mnL[N],mxR[N],mnR[N],mxL[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;//多测清空别忘了 
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i],mn[i]=mnL[i]=mnR[i]=n+1;mn[0]=n+1;mn[n+1]=n+1;
		for(int i=1;i<=n;i++){
			int l=i,r=n;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]-a[i]<=d)R[i]=mid,l=mid+1;
				else r=mid-1;
			}
			mn[R[i]]=min(mn[R[i]],i);
			l=1,r=i;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[i]-a[mid]<=d)L[i]=mid,r=mid-1;
				else l=mid+1;
			}
			mx[L[i]]=max(mx[L[i]],i);
		}
		for(int i=1;i<=n;i++){
			mnL[L[i]]=min(mnL[L[i]],i);
			mxL[L[i]]=max(mxL[L[i]],i);
			mnR[R[i]]=min(mnR[R[i]],i);
			mxR[R[i]]=max(mxR[R[i]],i);
		}
		for(int i=n;i;i--){
			if(L[R[i]]==i){
				kuai[i]=kuai[R[i]];
				int y=mxL[i];
				y=min(y,R[i]);
				int x=mnL[i];
				x=max(x,i+1);
				sum[i]=sum[R[i]];
				if(L[x]==i&&L[y]==i)sum[i]+=y-x+1;
				if(!kuai[i]){
					y=mxL[R[i]];
					if(y>R[i]&&L[y]==R[i]){
						 x=mnL[R[i]];
						x=max(x,R[i]+1);
						if(L[x]==R[i])sum[i]+=y-x+1;
					}
					kuai[i]=R[i];
				}
			}			
		}
		for(int i=1;i<=n;i++){
			if(R[L[i]]==i){
				kl[i]=kl[L[i]];
				int y=mxR[i];
				y=min(y,i-1);
				int x=mnR[i];
				x=max(x,L[i]);
				sum2[i]=sum2[L[i]];
				if(R[x]==i&&R[y]==i)sum2[i]+=y-x+1;
					if(!kl[i]){
					y=mxR[i];y=min(y,L[i]-1);
					x=mnR[i];
					if(R[y]==L[i]){
						sum2[i]+=y-x+1;
					}
					kl[i]=L[i];	
				}
			}
		}
		int ans=0;
		for(int i=2;i<=n;i++){
			int x=mn[i],y=R[i];
			if(x>n)continue;
			int x2=L[i-1],y2=mx[i-1];
			if(!y2)continue;
			int l=mxR[i];
			l=min(l,i-2);
			int l2=mnR[i];
			l2=min(l2,i-2);swap(l,l2);
			int r=mxL[i-1];
			r=max(r,i+1);
			int r2=mnL[i-1];
			r2=max(r2,i+1);
			swap(r,r2);int zuo=0,you=0;
			if(L[r2]==i-1&&R[l2]==i){
				zuo+=l2-l+1;you+=r2-r+1;
			//	if(i==6)cout<<i<<' '<<l<<' '<<l2<<' '<<r<<' '<<r2<<' '<<you<<endl;
			}
			int s1=0,s2=0;
			if(y==y2)s2=sum[y];if(x==x2)s1=sum2[x];
			s1+=zuo,s2+=you;
		//	if(i==6)cout<<i<<' '<<s1<<' '<<s2<<' '<<y<<endl;
			ans+=s1*s2;
		}
		cout<<ans<<endl;
		for(int i=0;i<=n;i++){
			mn[i]=R[i]=L[i]=kuai[i]=sum[i]=a[i]=mx[i]=kl[i]=sum2[i]=0;mxL[i]=0;mxR[i]=0;
		}
	}
	return 0;
}

