#include<bits/stdc++.h>
#define endl '\n'
#define int int64_t
//int8_t buf[1<<20],*p1,*p2;
//#define getchar() ((p1==p2&&p2=(p1=buf)+fread(buf,1,1<<20,stdin)&&(*p2=EOF)),*p1++)
//int read(){int k=0,f=1;int c=getchar();for(;c<'0'||c>'9';c=getchar()){if(c=='-'){f=-1;}}for(;c>='0'&&c<='9';c=getchar()){k=k*10+(c-'0');}return k*f;}
using namespace std;
int n,m,a[500010],cnt[300010];
int st[500010],tp=0,w[300010];
int32_t main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			w[i]=0;
		}
		tp=0;
		for(int j=i;j<=n;j++){
			if(w[a[j]]>tp||st[w[a[j]]]!=a[j]) w[a[j]]=0;
			if(w[a[j]]){
				tp=w[a[j]];
			}else{
				st[++tp]=a[j];
				w[a[j]]=tp;
			}
		}
		for(int i=1;i<=tp;i++){
			cnt[st[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<(i==m?endl:' ');
	}
	return 0;
}
