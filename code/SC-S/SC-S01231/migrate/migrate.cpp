#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull signed long long
#define pi pair<int,int>
const int N=2e6+10;
int nxt[N],x[N],st[N][20];
int pr[N],sf[N],n;
int dis(int l,int r){
	if(l>r)swap(l,r);
	if(st[l][19]<r)return 1e9;
	int ans=0;
	for(int i=19;~i;i--)if(st[l][i]<r)ans+=(1<<i),l=st[l][i];
	return ans+1;
}
bool chk(int l,int r){
	if(dis(l,r)==1e9)return false;
	int curp=0,d=dis(l,r),cur=l;
	while(true){
		cur=nxt[cur];
//		cout<<cur<<"CUR\n";
		if(cur<r){
			if(dis(l,cur-1)+dis(cur-1,r)==d){
				if(curp)return false;
				curp=cur;
				if(dis(l,cur-2)+dis(cur-2,r)==d)return false;
			}
		}
		else break;
	}
//	cout<<"MAN"<<curp<<"\n";
	if(curp)return true;
	return false;
}
void work(){
	int d;cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	int j=n;
	for(int i=n;i>=1;i--){
		while(x[j]-x[i]>d)j--;
		nxt[i]=j;
		st[i][0]=nxt[i];
	}
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			st[j][i]=st[st[j][i-1]][i-1];
		}
	}
	int ans=0;
//	cout<<chk(2,5)<<" "<<dis(2,5)<<"ck\n";
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(chk(i,j))ans++;
		}
	}
	cout<<ans<<"\n";
//	nxt[0]=nxt[1];
//	for(int i=n;i>=2;i--){
//		if(nxt[i]==nxt[i-1]&&nxt[i-2]<nxt[i]){
//			int val=nxt[i]-nxt[i-2];
//			sf[i]=sf[nxt[i]]+val;
//		}
//	}
//	for(int i=1;i<=n;i++)cout<<nxt[i]<<" ";
//	cout<<"\n";
//	
//	j=1;
//	for(int i=1;i<=n;i++){
//		while(x[i]-x[j]>d)j++;
//		nxt[i]=j;
//	}
//	nxt[n+1]=nxt[n];
//	for(int i=1;i<n;i++){
//		if(nxt[i]==nxt[i+1]&&nxt[i]<nxt[i+2]){
//			int val=nxt[i+2]-nxt[i];
//			pr[i]=pr[nxt[i]]+val;
//		}
//	}
//	int ans=0;
//	for(int i=1;i<=n;i++)ans+=sf[i]*pr[i];
//	for(int i=1;i<=n;i++)cout<<sf[i]<<" ";
//	cout<<"Print sf\n";
//	for(int i=1;i<=n;i++)cout<<pr[i]<<" ";
//	cout<<"Print pr\n";
//	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--)work();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 2
1 2 3 4 5
*/