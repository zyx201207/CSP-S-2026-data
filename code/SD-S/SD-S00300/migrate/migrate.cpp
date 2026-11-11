#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
int a[2000005];
int nex[2000005];
inline void clear(){
	for (int i=1;i<=n;i++){
		nex[i]=0;
		a[i]=0;
	}
	return;
}
inline int get(int x){
	return lower_bound(a+1,a+n+1,x)-a;
}

inline void bl(){
	int ans=0;
	for (int l=1;l<=n;l++){
		int sp=l;
		int flag=0;
		while (1){
			int pre=sp;
			sp=nex[sp];
			if (pre==sp){
				break;
			}
			
			int lsp=a[pre-1];
			int llsp=a[pre-2];
			if (pre-1>l){
				int td=lsp+d;
				int rr=upper_bound(a+1,a+n+1,min(td,a[sp]))-a-1;
				int ll;
				if (pre-2!=l){
					ll=upper_bound(a+1,a+n+1,min(llsp+d,a[sp]))-a;
				}
				else{
					ll=pre+1;
				}
				if (ll<=rr){
					ans+=(rr-ll+1);
					flag=1;
				}
				if (rr==sp){
					break;
				}
			}
			else if (flag){
				ans+=(sp-pre);
			}
		}
	}
	cout<<ans<<'\n';
	return;
}

inline void solveA(){
	int nd=nex[1];
	if (nex[1]<=2){
		cout<<"0\n";
		return;
	}
	nd=(nd-1)*2;
	if (nd>n){
		cout<<"0\n";
		return;
	}
	cout<<n-nd+1<<"\n";
	return;
}
inline void solveB(){
	if (nex[1]==n){
		cout<<"0\n";
		return;
	}
	int res=0;
	int pos=nex[1];
	for (int i=1;i<nex[1];i++){
		int r2=upper_bound(a+1,a+n+1,a[nex[i]]+d)-a-1;
		if (nex[i]>nex[1]){
			int r1=upper_bound(a+1,a+n+1,a[nex[1]-1]+d)-a-1;
			res+=r2-r1;
		}
		if (nex[i]<nex[1]){
			int r1=upper_bound(a+1,a+n+1,a[nex[i]-1]+d)-a-1;
			res+=r2-r1;
		}
	}
	cout<<res<<"\n";
	return;
}
int ff[20005];
int dd[20005];

inline int ss(int l,int r){
	dd[l]=0;
	ff[l]=1;
	for (int s=l;s<=r;s++){
		for (int t=s+1;t<=r;t++){
			if (a[s]+d>=a[t]){
				if (dd[t]>dd[s]+1){
					dd[t]=dd[s]+1;
					ff[t]=1;
				}	
				else if (dd[t]==dd[s]+1){
					ff[t]+=ff[s];
				}
			}
			else{
				break;
			}
		}
	}
	if (ff[r]==2){
		return 1;
	}
	return 0;
}
inline void Bl(){
	int res=0;
	for (int l=1;l<=n;l++){
		for (int r=l+1;r<=n;r++){
			for (int i=l;i<=r;i++){
				ff[i]=0;
				dd[i]=1e9;
			}
			res+=ss(l,r);
		}
	}
	cout<<res<<"\n";
	return;
}
int C,T;
inline void solve(){
	clear();
	cin>>n>>d;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		nex[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
	}
	if (11<=C && C<=12){
		solveA();
		return;
	}
	if (13<=C && C<=14){
		solveB();
		return;
	}
	if (n<=300){
		Bl();
		return;
	}
	else if (n<=5000){
		bl();
		return;
	}
	
	
	return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>C>>T;
	while (T--){
		solve();
	}
	return 0;
}
