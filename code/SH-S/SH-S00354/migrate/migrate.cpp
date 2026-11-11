#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// #define int ll
namespace leo{
	constexpr int N=2000005;
	int n,L[N],R[N],Li[N],Ri[N],Lc[N],Rc[N],cl[N],cr[N],tol[N],tor[N];ll d,x[N];
	void solve(){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		{
			for(int i=1;i<=n;i++)cl[i]=cr[i]=tol[i]=tor[i]=0;
			int p=1;
			for(int i=1;i<=n;i++){
				while(x[i]-x[p]>d)p++;
				L[i]=p;if(p!=i&&p+1!=i)cl[p]++;
				if(p!=i)tol[p]++;
			}
			p=n;
			for(int i=n;i>=1;i--){
				while(x[p]-x[i]>d)p--;
				R[i]=p;if(p!=i&&p-1!=i)cr[p]++;
				if(p!=i)tor[p]++;
			}
			for(int i=1;i<=n;i++){
				if(R[L[i]]==i)Li[i]=Li[L[i]],Lc[i]=Lc[L[i]]+tor[i];
				else Li[i]=i,Lc[i]=tor[i];
			}
			for(int i=n;i>=1;i--){
				if(L[R[i]]==i)Ri[i]=Ri[R[i]],Rc[i]=Rc[R[i]]+tol[i];
				else Ri[i]=i,Rc[i]=tol[i];
			}
		}
		// for(int i=1;i<n;i++)cout<<x[i+1]-x[i]<<endl;
		ll ans=0;
		// for(int i=1;i<=n;i++)cout<<i<<' '<<L[i]<<' '<<R[i]<<endl;
		// for(int i=1;i<=n;i++)cout<<i<<' '<<Lc[i]<<' '<<Rc[i]<<endl;
		for(int i=1;i<n;i++){
			if(x[i+1]-x[i]>d)continue;
			ll dans=ans;
			if(R[L[i]]==i+1&&L[R[i+1]]==i){
				ans+=1ll*(Lc[L[i]]+cr[i+1])*(Rc[R[i]]+cl[i]);
			}
			else if(R[L[i]]==i+1){
				ans+=1ll*(Lc[L[i]]+cr[i+1])*(cl[i]);
			}
			else if(L[R[i+1]]==i){
				ans+=1ll*(Rc[R[i]]+cl[i])*(cr[i+1]);
			}
			else ans+=1ll*(cl[i])*(cr[i+1]);
			// cout<<i<<' '<<ans<<' '<<1ll*(Lc[L[i]]+1)*(Rc[R[i]]+1)<<endl;
			// if(ans!=dans&&n!=399943){
			// 	cout<<i<<' '<<ans<<' '<<dans<<endl;
			// 	cout<<Lc[L[i]]<<' '<<Rc[R[i]]<<endl;
			// 	cout<<L[i]<<' '<<L[i+1]<<' '<<R[i]<<' '<<R[i+1]<<endl;
			// 	for(int j=i-10;j<=i+10;j++)cout<<x[j]<<' ';cout<<endl;
			// 	for(int j=i-10;j<=i+10;j++)cout<<L[j]<<' ';cout<<endl;
			// 	for(int j=i-10;j<=i+10;j++)cout<<R[j]<<' ';cout<<endl;
			// 	for(int j=i-10;j<=i+10;j++)cout<<Lc[j]<<' ';cout<<endl;
			// 	for(int j=i-10;j<=i+10;j++)cout<<Rc[j]<<' ';cout<<endl;
			// }
			// if(R[L[i]]==i+1&&L[R[i]]==i&&R[L[i+1]]==i+1&&L[R[i+1]]==i){
			// 	ans+=1ll*(Lc[L[i]]-1)*(Rc[R[i]]-1);
			// 	// cout<<"qwq "<<i<<endl;
			// }
			// if(i!=1&&R[L[i]]==i+1&&L[R[i]]==i&&R[L[i+1]]==i+1){
			// 	ans+=1ll*(Lc[L[i]]-1)*cl[i];
			// }
			// if(i!=n-1&&L[R[i]]==i&&R[L[i+1]]==i+1&&L[R[i+1]]==i){
			// 	ans+=1ll*(Rc[R[i]]-1)*cr[i+1];
			// }
			// ans+=1ll*cl[i]*cr[i+1];

				// cout<<R[L[i]]<<' '<<L[R[i]]<<' '<<R[L[i+1]]<<' '<<L[R[i+1]]<<endl;
			// cout<<i<<' '<<ans<<endl;
			// ans+=1ll*cl[i]*cr[i+1];
		}
		cout<<ans<<'\n';
	}
}

signed main(){
	 freopen("migrate.in","r",stdin);
	 freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;//t=1;
	while(t--)leo::solve();
}
