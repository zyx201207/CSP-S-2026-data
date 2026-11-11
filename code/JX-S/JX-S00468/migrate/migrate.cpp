#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int C,T,n,d,a[N],L[N],R[N],x2[N],tmp,cnt;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		for(int i=1;i<=n;i++)x2[i]=L[i]=R[i]=0;
		cnt=0;
		tmp=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int x1=1;x1<=n;x1++){
			int l=x1+1,r=n,ans=x1+1;
			if(a[x1]-a[x1-1]>d)tmp=0;
			while(l<=r){
				int mid=l+r>>1;
				if(a[mid]<=d+a[x1])ans=mid,l=mid+1;
				else r=mid-1;
			}
			if(ans==x1+1 || ans==n){
				x2[x1]=-1,L[x1]=-1,R[x1]=-1;
				tmp++;
			}
			else{
				x2[x1]=ans;
				
				l=x2[x1]+1,r=n,ans=x2[x1]+1;
				while(l<=r){
					int mid=l+r>>1;
					if(a[mid]<=d+a[x2[x1]-1])l=mid+1,ans=mid;
					else r=mid-1;
				}
				R[x1]=ans;
				
				l=x2[x1]+1,r=n+1,ans=x2[x1]+1;
				while(l<=r){
					int mid=l+r>>1;
					if(a[mid]>d+a[x2[x1]-2])r=mid-1,ans=mid;
					else l=mid+1;
				}
				L[x1]=ans;
				if(a[R[x1]]-a[x2[x1]-2] <= d || a[R[x1]]-a[x2[x1]-1] > d){
					x2[x1]=L[x1]=R[x1]=-1;
				}
				else{
					cnt+=(R[x1]-L[x1]+1)*(tmp+1);
					tmp=0;
				}
				
			}
		}
		
		//~ for(int i=1;i<=n;i++)cout<<x2[i]<<' '<<L[i]<<' '<<R[i]<<'\n';
		//~ cout<<"[1]"<<cnt<<'\n';
		cout<<cnt<<'\n';
	}
	return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
*/
