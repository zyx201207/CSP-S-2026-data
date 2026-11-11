#include<bits/stdc++.h>
#define int long long
using namespace std;
struct tnode{
	int tn,num;
};
int pos[2000005],dkt[2000005];
tnode f[5005][5005];
void A(int T){
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>pos[i];
		int l=pos[2]-pos[1];
		int oncepass=d/l;
		//cout<<n<<' '<<d<<' '<<l<<' '<<oncepass<<' ' ;
		if(oncepass==0||oncepass==1){
			cout<<0<<'\n';
			continue;
		}
		int lk=(oncepass*2-1);
		int ans=n-lk;
		int tt=0;
		cout<<max(ans,tt)<<'\n';
	}
	return;
}
void B(int T){
	while(T--){
		int n,d;
		cin>>n>>d;
		int l,r;
		int ans=0;
		for(int i=1;i<=n;i++) cin>>pos[i];
		for(int i=1;i<=n;i++){
			if(pos[i]-pos[1]<=d&&pos[n]-pos[i]<=d) l=i;
		}
		r=l+1;
		for(int i=1;i<l;i++){
			while(pos[r]-pos[i]<=d&&r<=n) r++;
			dkt[i]=r;
		}
		for(int i=1;i<l;i++){
			int q=2;
			if(dkt[i]==l+1) ans+=dkt[l-1]-max(dkt[l-2],q);
			if(dkt[i]==l+2) ans+=n-(dkt[l-1])+1;
		}
		cout<<ans<<'\n';
	}
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int c,T;
	cin>>c>>T;
	if(c==11||c==12){
		A(T);
		return 0;
	}
	if(c==13||c==14){
		B(T);
		return 0;
	}
	while(T--){
		int n,d;
		cin>>n>>d;
		tnode u;
		u.tn=1;
		u.num=1;
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j].num=998244353;
				f[i][j].tn=998244353;
			}
		}
		for(int i=1;i<=n;i++) cin>>pos[i];
		for(int i=1;i<n;i++){
			for(int j=1;j+i<=n;j++){
				if(pos[i+j]-pos[j]<=d){
					f[j][i+j]=u;
					continue;
				}
				for(int k=j+1;k<j+i;k++){
					if(f[j][j+i].tn<f[j][k].tn+f[k][j+i].tn) continue;
					else if(f[j][j+i].tn==f[j][k].tn+f[k][j+i].tn) f[j][j+i].num+=f[j][k].num*f[k][j+i].num;
					else{
						f[j][i+j].tn=f[j][k].tn+f[k][j+i].tn;
						f[j][j+i].num=f[j][k].num*f[k][j+i].num;
					}
				}
				if(f[j][i+j].tn>=3) f[j][i+j].num/=(f[j][i+j].tn-1);
				if(f[j][i+j].num==2) cnt++;
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) cout<<f[i][j].num<<' ';
			cout<<endl;
		}*/
		cout<<cnt<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
