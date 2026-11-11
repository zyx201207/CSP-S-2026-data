#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e6+5;
int C,T,n,dp[N],p,q,c[N],aa,ab,ac;
ll d,a[N],l;
void check(int x,int D){
	if(c[x]==0){
		aa+=D;
	}else if(c[x]==1){
		ab+=D;
	}else{
		ac+=D;
	}
}
int erfen(ll x){
	int le=1,ri=n,an;
	while(le<=ri){
		int mi=(le+ri)>>1;
		if(a[mi]<=x){
			an=mi;
			le=mi+1;
		}else{
			ri=mi-1;
		}
	}
	return an;
}
int erfena(ll x){
	int le=1,ri=n,an;
	while(le<=ri){
		int mi=(le+ri)>>1;
		if(a[mi]>x){
			an=mi;
			ri=mi-1;
		}else{
			le=mi+1;
		}
	}
	return an;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>T;
//	C=13;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		l=0;
		if(C<=10){
			for(int s=1;s<=n;s++){
				for(int i=1;i<=n;i++){
					dp[i]=0x3f3f3f3f;
					c[i]=0;
				}
				dp[s]=0;
				p=s,q=s-1;aa=ab=ac=0;
				for(int i=s+1;i<=n;i++){
					while(a[i]-a[p]>d){
						check(p,-1);
						p++;
					}
					if(p==i){
						break;
					}
					while(q<p||dp[p]==dp[q+1]){
						q++;
						check(q,1);
					}
					dp[i]=dp[p]+1;
//					cerr<<s<<i<<p<<q<<aa<<ab<<endl;
					if(aa==2&&ab==0&&ac==0){
						l++;
						c[i]=1;
//						cerr<<"ok";
					}else if(aa==0&&ab==1&&ac==0){
						l++;
						c[i]=1;
//						cerr<<"ok";
					}else if(aa==1&&ab==0&&ac==0){
						;
					}else{
						c[i]=2;
					}
				}
//				for(int i=1;i<=n;i++){
//					cerr<<c[i]<<" ";
//				}cerr<<endl;
			}
			cout<<l<<endl;
		}else if(C==11||C==12){
			int s=1;
			for(int i=1;i<=n;i++){
					dp[i]=0x3f3f3f3f;
					c[i]=0;
				}
				dp[s]=0;
				p=s,q=s-1;aa=ab=ac=0;
				for(int i=s+1;i<=n;i++){
					while(a[i]-a[p]>d){
						check(p,-1);
						p++;
					}
					if(p==i){
						break;
					}
					while(q<p||dp[p]==dp[q+1]){
						q++;
						check(q,1);
					}
					dp[i]=dp[p]+1;
//					cerr<<s<<i<<p<<q<<aa<<ab<<endl;
					if(aa==2&&ab==0&&ac==0){
						l+=(n-i+1);
						c[i]=1;
//						cerr<<"ok";
					}else if(aa==0&&ab==1&&ac==0){
						l+=(n-i+1);
						c[i]=1;
//						cerr<<"ok";
					}else if(aa==1&&ab==0&&ac==0){
						;
					}else{
						c[i]=2;
					}
				}
				cout<<l<<endl;
		}else if(C==13||C==14){
			p=1,q=1;
			for(int i=1;i<=n;i++){
				while(erfen(a[i]+d)-erfena(a[p]-d)>2&&p<n){
					p++;
				}
				while(erfen(a[i]+d)-erfena(a[q]-d)>1&&q<n){
					q++;
				}
				l+=q-p-1;
			}
			cout<<l<<endl;
		}else{
			for(int s=1;s<=n;s++){
				for(int i=1;i<=n;i++){
					dp[i]=0x3f3f3f3f;
					c[i]=0;
				}
				dp[s]=0;
				p=s,q=s-1;aa=ab=ac=0;
				for(int i=s+1;i<=n;i++){
					while(a[i]-a[p]>d){
						check(p,-1);
						p++;
					}
					if(p==i){
						break;
					}
					while(q<p||dp[p]==dp[q+1]){
						q++;
						check(q,1);
					}
					dp[i]=dp[p]+1;
//					cerr<<s<<i<<p<<q<<aa<<ab<<endl;
					if(aa==2&&ab==0&&ac==0){
						l++;
						c[i]=1;
//						cerr<<"ok";
					}else if(aa==0&&ab==1&&ac==0){
						l++;
						c[i]=1;
//						cerr<<"ok";
					}else if(aa==1&&ab==0&&ac==0){
						;
					}else if(aa==0&&ab==0){
						break;
					}else{
						c[i]=2;
					}
				}
//				for(int i=1;i<=n;i++){
//					cerr<<c[i]<<" ";
//				}cerr<<endl;
			}
			cout<<l<<endl;
		}
	}
	return 0;
}
//Oct31==Dec25?
/*
schedule
14:30-15:00 T1_t+w
15:00-15:45 T2_t+T3_t
15:45-16:45 T2_w
16:45-17:45 T3_w
17:45-18:15 T4_t+w

time table
14:39 KT1
16:30 KT2
#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e6+5;
int C,T,n,p;
ll d,a[N],l;
int erfen(ll x){
	int le=1,ri=n,an;
	while(le<=ri){
		int mi=(le+ri)>>1;
		if(a[mi]<=x){
			an=mi;
			le=mi+1;
		}else{
			ri=mi-1;
		}
	}
	return an;
}
int erfena(ll x){
	int le=1,ri=n,an;
	while(le<=ri){
		int mi=(le+ri)>>1;
		if(a[mi]>=x){
			an=mi;
			ri=mi-1;
		}else{
			le=mi+1;
		}
	}
	return an;
}
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		l=0;
		
//		if(C!=11&&C!=12){
//			for(int s=1;s<=n;s++){
//				int x=erfen(a[s]+d);
//				l+=n-x;
//				while(x<n){
//					int y=erfen(a[x]+d);
//					int z=erfena(a[y]-d);
////					cerr<<s<<x<<y<<z<<"p"<<endl;
//					if(x==y||y==z){
//						l-=n-y;
//						break;
//					}
//					if(x==z){
////					cerr<<y<<"nonono"<<endl;
//						l--;
//					}
//					x=y;
//				}
//			}
//			cout<<l<<endl;
//		}else{
//			
//		}
	}
	return 0;
}
//Oct31==Dec25?

schedule
14:30-15:00 T1_t+w
15:00-15:45 T2_t+T3_t
15:45-16:45 T2_w
16:45-17:45 T3_w
17:45-18:15 T4_t+w

time table
14:39 KT1
16:30 KT2
*/
