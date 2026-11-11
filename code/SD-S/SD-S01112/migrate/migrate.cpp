#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=3e6;
int n;
int d;
int x[N];
int f[N];//2
int g[N];//1
int Add1[N];
int Add2[N];
int R[N];
int R2[N];
void get(int L1,int R1,int l,int r,int &F1,int &F2,int Fl){
	int lll=L1;
	int rrr=R1;
	int ass=-1;
	while(lll<=rrr){
		int Mid=(lll+rrr)>>1;
		if(x[Mid]>=l)ass=Mid,rrr=Mid-1;
		else lll=Mid+1;
	}
	int L_=ass;
	lll=L1;
	rrr=R1;
	ass=-1;
	while(lll<=rrr){
		int Mid=(lll+rrr)>>1;
		if(x[Mid]<=r)ass=Mid,lll=Mid+1;
		else rrr=Mid-1;
	}
	int R_=ass;
	if(L_<=R_&&L_!=-1){
		F1+=R_-L_+1;
		F2=R_-L_+1;
		int ss=g[R_];
		if(ss&&Fl)F2+=ss-1,F1+=ss-1;
	}
	return;
}
void solve(){
	n=read();
	d=read();
	for(int i=1;i<=n;i++)x[i]=read();
	int ans=0;
	for(int i=n;i>=1;i--){
		int l=i;
		int r=n;
		int As=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(x[mid]-x[i]<=d)As=mid,l=mid+1;
			else r=mid-1; 
		}
		if(As>i)g[i]=As-i+g[As];
		else g[i]=1;
		R[i]=As;
		if(R[i]==R[i+1])g[i+1]=1;
		else{
			int ll=i+2;
			int rr=n;
			int as=-1;
			while(ll<=rr){
				int midd=(ll+rr)>>1;
				if(x[midd]-x[i]<=d&&x[midd]-x[i+1]<=d)as=midd,ll=midd+1;
				else rr=midd-1;
			}
			if(as!=-1)g[i+1]-=as-(i+2)+1;
		}
		f[i]=f[As];
		Add1[i]=f[As];
		vector<int>G;
		int P=As;
		while(P>i){
			G.push_back(P);
			P--;
			if(G.size()==3)break;
		}
		reverse(G.begin(),G.end());
		if((int)G.size()==2){
			int l1=x[i+2];
			int r1=x[i+1]+d;
			R2[i]=G[0];
			int Fl=(R[i+1]==R[i+2]);
			get(i+3,n,l1,r1,f[i],Add2[i],Fl);
		}
		if((int)G.size()>2){
			int A1=G.back();
			G.pop_back();
			int A2=G.back();
			R2[i]=A2;
			G.pop_back();
			int A3=G.back();
			G.pop_back();
			int P1=A1;
			int P2=A2;
			A1=x[A1];
			A2=x[A2];
			A3=x[A3];
			int l1=max(A3+d+1,A1);
			int r1=A2+d;
			int Fl=(R[P1]==R[P2]);
			get(R[i]+1,n,l1,r1,f[i],Add2[i],Fl);
		}
		if(!R2[i])R2[i]=R[i];
		if(R[i]==R[i+1]){
			f[i+1]=0;
		}
		if(R[i]==R2[i+1]){
			f[i+1]-=Add2[i+1];
		}
		ans+=f[i];
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)f[i]=g[i]=Add1[i]=Add2[i]=R[i]=R2[i]=0;
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read();
	int T=read();
	while(T--)solve(); 
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
//10 22
//0 7 14 21 28 35 42 49 56 63 

