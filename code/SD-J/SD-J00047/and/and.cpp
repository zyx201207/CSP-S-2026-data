#include<bits/stdc++.h>
using namespace std;
#define int long long
int rd(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+c^48,c=getchar();
	return s*f;
}
int n,m,a[200005],vis[25],ans=1,pow2[35];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool ax4=1;
	for(int i=1;i<=n;i++)
		if(a[i]>4){
			ax4=0;
			break;
		}
	if(ax4){
		sort(a+1,a+1+n);
		bool c1=0,c2=0,c3=0,c4=0;
		int r1=0,r2=0,r3=0,r4=0;
		for(int i=1;i<=n;i++)
			if(a[i]==1) c1=1,r1++;
			else if(a[i]==2) c2=1,r2++;
			else if(a[i]==3) c3=1,r3++;
			else c4=1,r4++;
		if(m==1){
			if(c4)cout<<4;
			else if(c3) cout<<3;
			else if(c2) cout<<2;
			else if(c1) cout<<1;
			else cout<<0;
			return 0;
		}
		if(m==2){
			if(r4>=2) cout<<4;
			else if(r3>=2) cout<<3;
			else if(r2>=2) cout<<2;
			else if(c2&&c3) cout<<2;
			else if(r1>=2) cout<<1;
			else if(c1&&c3) cout<<1;
			else cout<<0;
			return 0;
		}
		if(r4>=m) cout<<4;
		else if(r3>=m) cout<<3;
		else if(r2>=m) cout<<2;
		else if(r1>=m) cout<<1;
		else if(r3+r2>=m) cout<<2;
		else if(r3+r1>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	if(m==1){
		int maxn=-1;
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		cout<<maxn<<"\n";
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++) a[i]&=a[i-1];
		cout<<a[n];
		return 0;
	}
	if(m==n-1&&a[1]!=0){
		int cn=-1;
		for(int i=1;i<=n;i++){
			if(i!=1) ans=a[1];
			else ans=a[2];
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				ans&=a[j];
			}
			cn=max(cn,ans);
		}
		cout<<cn;
		return 0;
	}
	for(int i=1;i<=30;i++) pow2[i]=pow(2,i);
	bool pows=1;
	for(int i=1;i<=n;i++){
		bool poe=0;
		for(int j=1;j<=30;j++)
			if(a[i]==pow2[j]-1){
				poe=1;
				break;
			}
		if(!poe) pows=0;
		if(!pows) break;
	}
	if(pows){
		sort(a+1,a+1+n);
		for(int i=n-1;i>=n-m+1;i--) a[i]&=a[i+1];
		cout<<a[n-m+1];
		return 0;
	}
	bool pn=0,ap=1;
	int np;
	for(int i=1;i<=30;i++)
		if(n==pow2[i]){
			pn=1,np=i;
			break;
		}
	for(int i=1;i<=n;i++)
		if(a[i]!=i-1){
			ap=0;
			break;
		}
	if(pn&&ap){
		cout<<n-m-1;
		return 0;
	}
	sort(a+1,a+1+n);
	cout<<a[n];
	return 0;
}
