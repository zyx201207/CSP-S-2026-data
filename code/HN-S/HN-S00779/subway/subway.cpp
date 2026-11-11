#include<bits/stdc++.h>
using namespace std;
int m,n,v[505],k[500005],cr,d,q,w1,w2,ans,ji,s[501][21],mi=100000000,jia[500005],y=1;
void solve(int cnt,int d,int z){
//	cout<<"???"<<endl;
	if(cnt>mi) return; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<y;j++){
			if(s[i][jia[j]]!=0 && s[i][d]!=0 && d!=jia[j]){
				cnt=cnt+s[i][d]+s[i][jia[j]];
//				cout<<"???"<<i<<" "<<d<<" "<<jia[j]<<" "<<cnt<<" "<<endl;
				int x=d;
				d=jia[j];
				solve(cnt,d,z);
				d=x;
				cnt=cnt-s[i][d]-s[i][jia[j]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i][d]!=0 && s[i][z]!=0){
			if(d!=z) cnt=cnt+s[i][d];
//			cout<<"???"<<i<<" "<<d<<" "<<cnt<<" ";
			ans=ans-mi;
			mi=min(mi,cnt);
//			cout<<"???"<<mi<<endl;
			ans=ans+mi;
			return;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cr>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>k[i];
	for(int i=1;i<=n;i++){
		cin>>v[i];
		for(int j=1;j<=v[i];j++) cin>>ji>>s[i][ji];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				for(int u=1;u<=min(v[i],v[j]);u++){
					if(s[i][u]!=0 && s[j][u]!=0) jia[y]=u,y++;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		mi=100000000;
		cin>>w1>>w2;
//		cout<<"???"<<k[w1]<<" "<<k[w2]<<endl;
		ans=k[w1]+k[w2]+mi;
//		cout<<"???"<<ans<<endl;
		solve(0,w1,w2);
		cout<<ans<<endl;
	}
	return 0;
}

