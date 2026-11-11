#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e6+5;
int c,T;
int n,d;
int x[MAXN];
bool isdouble[MAXN];
struct node{
	int l,r;
};
vector<int> doublepos;
vector<node> lines;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		
		for(int i=1;i<=n-3;i++){
			bool flag1=(x[i+2]-x[i])<=d;
			bool flag2=(x[i+3]-x[i+1])<=d;
			bool flag3=(x[i+3]-x[i])>d;
			if(flag1 && flag2 && flag3) isdouble[i]=1;
			if(isdouble[i]) doublepos.push_back(i);
//			if(isdouble[i]) cerr<<i<<' ';
		}
//		cerr<<endl;
		int pre=1;
		for(int i=2;i<=n;i++){
			bool flag=(x[i]-x[i-1])<=d;
			if(flag) continue;
			else{
				node buf;
				buf.l=pre;
				buf.r=i-1;
				lines.push_back(buf);
				pre=i;
			}
		}
		
//		cerr<<"pre: "<<pre<<endl; 
		
		do{
			node buf;
			buf.l=pre;
			buf.r=n;
			lines.push_back(buf);
		}while(0);
		
		int ans=0;
		int linei=0;
		
		for(int i=0;i<lines.size();i++){
//			cerr<<"line: "<<lines[i].l<<' '<<lines[i].r<<endl;
		}
		
		for(int i=0;i<doublepos.size();i++){
			while(linei<lines.size() && lines[linei].r<doublepos[i]) linei++;
//			cerr<<"linei: "<<linei<<endl;
			int l,r;
			if(i==0) l=1;
			else l=doublepos[i-1]+1;
			l=max(l,lines[linei].l);
			if(i==doublepos.size()-1) r=n;
			else r=doublepos[i+1]+2;
			r=min(r,lines[linei].r);
			int len1=(doublepos[i]-l+1);
			int len2=(r-doublepos[i]-3+1);
//			cerr<<"from1: "<<doublepos[i]<<' '<<l<<endl;
//			cerr<<"from2: "<<r<<' '<<doublepos[i]+3<<endl;
			
			ans+=len1*len2; 
		}
		cout<<ans<<endl;
		
		for(int i=1;i<=n;i++) x[i]=0;
		for(int i=1;i<=n;i++) isdouble[i]=0;
		doublepos.clear();
		lines.clear();
	}
	return 0;

