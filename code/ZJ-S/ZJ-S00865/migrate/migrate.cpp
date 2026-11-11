#include<bits/stdc++.h>
#define int long long
#define il inline
#define put putchar
#define pb emplace_back
#define fir first
#define sec second
#define mk make_pair
using namespace std;
typedef pair<int,int> pii;
il int rd(){
	int sum=0,p=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		sum=sum*10+(ch-'0');
		ch=getchar(); 
	}
	return sum*p;
}
il void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}
const int JYAAKIOI=1e18,N=2e6+5,M=5e5+5;
int n,d,a[N],cid,f[N],g[N],l[N],r[N],id[N];
il void jyacanfly(){
	n=rd();d=rd();
	for(int i=1;i<=n;++i)a[i]=rd();
	if(cid<=10){
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j)g[j]=f[j]=0;
			f[i]=f[i-1]=0;g[i-1]=0,g[i]=1;int idx=0,pos=i;
			l[++idx]=i;r[idx]=i;id[i]=1;
			for(int j=i+1;j<=n;++j){
				if(a[j]-a[j-1]>d)break;
				while(a[j]-a[pos]>d)++pos;
				f[j]=f[pos]+1;
				g[j]=g[r[id[pos]]]-g[pos-1];
				if(f[j]==f[j-1])++r[idx],id[j]=idx;
				else l[++idx]=j,r[idx]=j,id[j]=idx;
				if(g[j]==2)++ans;
			//	cout<<f[j]<<" "<<g[j]<<" "<<r[id[pos]]<<" "<<pos-1<<"   ";
				g[j]+=g[j-1];
			}
		//	cout<<endl;
		}
		wr(ans),put('\n');
	}
	if(cid==11||cid==12){
		int k=d/(a[2]-a[1]),ans=0;
		if(k<=1){
			wr(ans),put('\n');
			return;
		}
		for(int i=1;i<=n;++i)if(i+k*2-1<=n)++ans;
//		if(n==10){
//			for(int i=1;i<=10;++i)cout<<a[i]<<" ";
//			cout<<"    "<<d<<"   ";
//		}
		wr(ans),put('\n');
	}
	if(cid==13||cid==14){
		
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cid=rd();int T=rd();
	while(T--)jyacanfly();
	return 0;
}