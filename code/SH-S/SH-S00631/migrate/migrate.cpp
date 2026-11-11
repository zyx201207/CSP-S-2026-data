#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+9;
int n,d,x[N];
int l[N],r[N],mkl[N],mkr[N],vl[N],vr[N],kl[N],kr[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			l[i]=r[i]=mkl[i]=mkr[i]=0;
			vl[i]=vr[i]=1;
			kl[i]=kr[i]=0;
		}
		int mk=1;
		for(int i=1;i<=n;i++){
			while(mk<=n&&x[mk]-x[i]<=d) mk++;
			r[i]=mk-1;
		}
		for(int i=1;i<=n;i++){
			if(r[i]==i){
				
			}
			else if(r[i]==i+1){
				vl[i+1]+=vl[i];
			}
			else if(r[i]>i+1){
				mkr[r[i]]+=(vl[i]+kl[i]);
				if(r[r[i]-1]<r[r[i]]-1)
					kl[r[i]]+=vl[i];
			}
		}
		mk=n;
		for(int i=n;i>=1;i--){
			while(mk>=1&&x[i]-x[mk]<=d) mk--;
			l[i]=mk+1;
		}
		for(int i=n;i>=1;i--){
			if(l[i]==i){
				
			}
			else if(l[i]==i-1){
				vr[i-1]+=vr[i];
			}
			else if(l[i]<i-1){
				mkl[l[i]]+=(kr[i]+vr[i]);
				if(l[l[i]+1]>l[l[i]]+1)
					kr[l[i]]+=vr[i];
			}
		}
		int ans=0;
		for(int i=1;i<n;i++){
			ans+=mkl[i]*mkr[i+1];
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
0 1
6 4
0 1 4 6 8 10
*/
