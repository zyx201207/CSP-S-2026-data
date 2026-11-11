#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e6+10;
inline int read(){
	char c=getchar();LL ans=0,p=1;
	while (c<'0'||c>'9'){if (c=='-') p=-1;c=getchar();}
	while (c>='0'&&c<='9'){ans=ans*10+(c-48);c=getchar();}
	return ans*p;
}
LL a[N];
LL cnt;
void f(LL t,LL n,LL d){
	map<int,int> mp,m;
		for (int i=1;i<=n;i++){
			m[i]=1e9;
		}
		m[t]=0;
		mp[t]=1;
		for (int i=t;i<=n;i++){
			for (int j=i+1;abs(a[j]-a[i])<=d;j++){
				if (m[j]>m[i]+1){
					m[j]=m[i]+1;
					mp[j]=mp[i];
				}else if (m[j]==m[i]+1){
					mp[j]+=mp[i];
				}
			}
		}
		for (int i=t;i<=n;i++){
			if (mp[i]==2) cnt++;
		}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while (t--){
		LL n=read(),d=read();
		for (int i=1;i<=n;i++){
			a[i]=read();
		}
		cnt=0;
		for (LL i=1;i<=n;i++){
			f(i,n,d);
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
