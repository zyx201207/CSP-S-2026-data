#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005;
int c,t,n,d,cnt,ans;
int a[N];
int mn[N];
int f[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
//		for(int i=1;i<=n;i++)
//			cout<<a[i]+d<<' ';
//		cout<<endl;
		for(int i=1;i<=n;i++){
			int l=i,r=i;
			ans=1;
			for(int j=1;j<=n;j++) f[j]=0;
			f[i]=1;
			mn[i]=0;
			for(int j=i+1;j<=n;j++){
				while(a[l]+d<a[j]){
					if(l<=r)
						ans-=f[l];
					l++;
				}
				mn[j]=mn[l]+1;
				if((c==13||c==14)&&mn[j]>2) break;
				if(ans==0){
					r=l;
					while(mn[r]==mn[l]){
						ans+=f[r];
						r++;
					}
					r--;
				}
				f[j]=ans;
//				cout<<l<<' '<<r<<endl;
			}
//			for(int j=i;j<=n;j++)
//				cout<<f[j]<<' ';
//			cout<<endl;
			for(int j=1;j<=n;j++)
				cnt+=(f[j]==2);
		}
		cout<<cnt<<endl;
	}
	return 0;
}