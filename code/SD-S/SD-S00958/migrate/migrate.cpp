#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
int c,T,n,d;
int a[2001000];
int f[2001000],g[2001000];
int q[2001000],hd,tl;
signed main(){
//	system("fc migrate.out migrate4.ans");return 0;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
//			cout<<a[i]+1000000000000000000ll<<' ';
		}
		if(c<=10){
			int ans=0;
			for(int i=1;i<=n;i++){
				hd=1,tl=0;
				f[i]=0,g[i]=1;
				q[++tl]=i;
				for(int j=i+1;j<=n;j++){
					while(hd<=tl&&a[q[hd]]+d<a[j]) hd++;
					if(hd>tl) break;
					f[j]=f[q[hd]]+1;
					int x=hd;
					g[j]=0;
					while(x<=tl&&f[q[x]]+1==f[j]&&g[j]<=2) g[j]+=g[q[x++]];
//					cout<<i<<' '<<j<<' '<<f[j]<<' '<<g[j]<<'\n';
					if(g[j]==2) ans++;
					while(tl>=hd&&f[q[tl]]>f[j]) tl--;
					q[++tl]=j;
				}
			}
			cout<<ans<<"\n";
		}
		else if(c<=12){
			int ans=0;
			int D=d/(a[2]-a[1]);
//			cout<<D<<"----"<<'\n';
			if(D==0||D==1){
				cout<<"0\n";
				continue;
			}
			for(int i=1;i<=n;i++){
				if(i+D+D-1<=n) ans++;
			}
			cout<<ans<<'\n';
		}
		else if(c<=14){
			int ans=0;
			int p=0,c=0;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d){
					c++,p=i;
				}
			}
			if(c>2){
				cout<<"0\n";
				continue;
			}
			int p1=0,p2=0,p3=0;
			for(int i=1;i<=n;i++){
				while(p1<n&&a[p1+1]<=a[i]+d) p1++;
				while(p2<n&&a[p2+1]<=a[p1-1]+d) p2++;
				while(p3<n&&a[p3+1]<=a[p1-2]+d) p3++;
				ans+=p2-p3;
			}
			cout<<ans<<'\n';
		}
		//失败了 磕了3h 假了/没调出来
		//再见了WC
		//不不不不不不不不不不不我无疑是愤怒的
		//早知道直接大暴力了 
//		 
////		cout<<"\n";
//		int l=1,r=1;
//		for(int i=1;i<=n;i++){
//			while(a[r]<a[i]-d) r++;
//			if(i==r) f[i]=0;
//			else{
//				while(a[l]<a[r+1]-d) l++;
//				if(l==1||a[l-1]+d<a[r]) f[i]=i-r;
//				else if(l<r) f[i]=f[r]+i-r-(r-l);
//				else f[i]=f[r]+i-r;
//			}
//		}
//		l=n,r=n;
//		for(int i=n;i>=1;i--){
//			while(a[l]>a[i]+d) l--;
//			if(i==l) g[i]=0;
//			else{
//				while(a[r]>a[l-1]+d) r--;
//				if(r==n||a[r+1]-d>a[l]) g[i]=l-i;
//				else if(l<r) g[i]=g[l]+l-i-(r-l);
//				else g[i]=g[l]+l-i;
//			}
//		}
////		for(int i=1;i<=n;i++){
////			cout<<f[i]<<' '<<g[i]<<'\n';
////		}
//		l=1;
//		for(int i=1;i<=n;i++){
//			while(a[l]<a[i]-d) l++;
//			pr[i]=i-l+1+pr[i-1];
//		}
//		r=0;
//		for(int i=1;i<=n;i++){
//			while(r<n&&a[r+1]<=a[i]+d) r++;
//			sf[i]=r-i+1+sf[i-1];
//		}
//		int ans=0;
//		int ll=1,rr=0;
//		for(int i=1;i<n;i++){
//			int L=i+1-(pr[i+1]-pr[i])+1;
//			int R=i+(sf[i]-sf[i-1])-1;
//			if(i==L||i+1==R) continue;
//			int lt=i+2-(pr[i+2]-pr[i+1])+1;
//			int rt=i-1+(sf[i-1]-sf[i-2])-1;
//			if(lt==L||rt==R) continue;
//			int F,G;
//			if(L+1==lt) F=f[L];
//			else{
//				while(a[ll]<a[L+1]-d) ll++;
//				if(ll==1||a[ll-1]<a[L]-d) F=0;
//				else F=f[L]-(L-ll);
//			}
//			if(R-1==rt) G=g[R];
//			else{
//				while(rr<n&&a[rr+1]<=a[R-1]+d) rr++;
//				if(rr==n||a[rr+1]>a[R]+d) G=0;
//				else G=g[R]-(rr-R);
//			}
//			cout<<i<<' '<<L<<' '<<lt<<' '<<rt<<' '<<R<<' '<<F<<' '<<G<<'\n';
//			ans+=(F+lt-L)*(G+R-rt);
//		}
//		cout<<ans<<"\n";
	}
	return 0;
}

