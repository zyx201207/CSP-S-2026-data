#include <bits/stdc++.h>
#define int long long
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
/*
by qqqaaazzz

CSP - 2026 !

稍微感觉一下，其实条件非常严格

有一些边叫做稳定的边，随便走

然后不稳定的，只有一种吗？？？ 

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

~16:00

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
int n,d;
int x[2000010];
int r[2000010],l[2000010];//

int cnt[2000010][2][2];
//vector<pair<int,int> > qrys[2000010];
struct Node{
	int x,y,z;
};
Node qrys[8000010];

int res[4000010];

int ans[2000010];
int tong[2000010];
//rem & myF state.

int solve(int _,int __){
//	cout<<_<<" "<<__<<"?\n";
	int final=0;
	for(int i=_;i<=__;i++){
		cnt[i][0][0]=cnt[i][0][1]=cnt[i][1][0]=cnt[i][1][1]=0;
	}
	for(int i=_;i<=__;i++){
		++cnt[i][0][0];
		for(int rem=0;rem<2;rem++){
			for(int myF=0;myF<2;myF++){
				int val=0;
				int lst=i,cur=l[i];
				if(rem==0)val=res[i];
				else val=res[n+i];
//				cout<<cur+1<<" "<<l[cur]<<"^^\n";
//				for(int m=cur+1;m<=l[cur];m++){
//					if(rem==0){
//						if(r[m]==cur-1)++val;//,cout<<i<<" "<<m<<"!\n";
//					}
//					else{
//						if(r[m]==cur)++val;//,cout<<i<<" "<<m<<".\n";
//					}
//				}
				
				if(rem==0)val*=((myF==0?max(r[cur-1],lst):r[cur-1])==lst);
				
				int nrem=rem,nmyF=myF;
				
				bool go=1;
				if(r[l[cur]]==cur-1){
					if((myF==0?max(r[cur-1],lst):r[cur-1])==lst);//ok
					else go=0;
					if(rem)go=0;
					nrem=1;
				}
				else if(r[l[cur]]==cur){
					//boring
				}
				else go=0;
				if(l[cur]==cur)go=0;
				nmyF=1;
				
				if(go)cnt[cur][nrem][nmyF]+=cnt[i][rem][myF];
				final+=cnt[i][rem][myF]*val;
//				lst=cur;
//				cur=l[cur];
//				myF=1;
			}
		}
	}
//	for(int i=_;i<=__;i++){
////		cout<<l[i]<<" "<<r[i]<<"*\n";
////		continue;
////		int cur=i;
////		cout<<l[i]<<" "<<r[i]<<"*\n";
////		if(r[l[l[i]]]==l[i]-1&&r[l[i]-1]==i){
////			cout<<i<<" "<<l[i]<<" "<<l[l[i]]<<" sturdy\n";
////		}
//		int lst=i,cur=l[i];
//		bool rem=0;
//		bool myF=0;
//		while(1){
////			cout<<i<<" "<<cur<<" "<<rem<<"(\n";
//			for(int m=cur+1;m<=l[cur];m++){
//				//try i~m ok ?
//				if(rem==0){
//					if(r[m]==cur-1&&(myF==0?max(r[cur-1],lst):r[cur-1])==lst)++final;//,cout<<i<<" "<<m<<"!\n";
//				}
//				else{
//					if(r[m]==cur)++final;//,cout<<i<<" "<<m<<".\n";
//				}
//			}
////			if(rem){
////				if(r[m]
////			}
//			if(r[l[cur]]==cur-1){
//				if((myF==0?max(r[cur-1],lst):r[cur-1])==lst);//ok
//				else break;
//				if(rem)break;
//				rem=1;
//			}
//			else if(r[l[cur]]==cur){
//				//boring
//			}
//			else break;
//			if(l[cur]==cur)break;
//			lst=cur;
//			cur=l[cur];
//			myF=1;
//		}
//	}
	return final;
}
bool cmp(Node x,Node y){
	return x.x<y.x;
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	x[n+1]=4000000000000000000;
	l[0]=1;
	for(int i=1;i<=n;i++){
		l[i]=l[i-1];
		while(x[l[i]+1]-x[i]<=d)++l[i];
	}
	r[n+1]=n;
	for(int i=n;i>=1;i--){
		r[i]=r[i+1];
		while(r[i]>1&&x[i]-x[r[i]-1]<=d)--r[i];
	}
	int cnt=0;
	for(int i=1;i<=2*n;i++)res[i]=0,tong[i]=0;
	
	for(int i=1;i<=n;i++){
		int G=l[l[i]],T=l[i];
		qrys[++cnt]={G,l[i]-1,i};
		qrys[++cnt]={T,l[i]-1,-i};
//		qrys[++cnt]={G,l[i],n+i};
//		qrys[++cnt]={T,l[i],-(n+i)};
	}
	sort(qrys+1,qrys+cnt+1,cmp);
	qrys[cnt+1]={0,0,0};
	
	int tot=0;
	for(int i=1;i<=n;i++){
		++tong[r[i]];
		while(qrys[tot+1].x==i){
			++tot;
			res[abs(qrys[tot].z)]+=(qrys[tot].z<0?-1:1)*tong[qrys[tot].y];
			res[abs(qrys[tot].z)+n]+=(qrys[tot].z<0?-1:1)*tong[qrys[tot].y+1];
		}
	}
	int ans=0,lst=1;
	for(int i=1;i<=n;i++){
		if(x[i+1]-x[i]>d){
			ans+=solve(lst,i);
			lst=i+1;
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
//	cout<<sizeof(qrys);
//	system("fc /n 1.out 2.out");
//	freopen("3.in","r",stdin);
//	freopen("2.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	FAST;
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}

