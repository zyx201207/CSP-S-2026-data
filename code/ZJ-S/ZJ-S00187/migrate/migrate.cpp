#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,x[2000001],a[2000001],cnt,ans,l[2000001],r[2000001],tot,b[2000001],pre[2000001],nxt[2000001];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cnt=ans=tot=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		l[1]=1;
		for(int i=2;i<=n;i++){
			if(x[i]-x[i-1]<=d)l[i]=l[i-1];
			else l[i]=i;
		}
		r[n]=n;
		for(int i=n-1;i>=1;i--){
			if(x[i+1]-x[i]<=d)r[i]=r[i+1];
			else r[i]=i;
		}
		for(int i=1;i<=n;i++)cerr<<l[i]<<" "<<r[i]<<endl;
		int p=1;
		for(int i=1;i<=n;i++){
			while(x[p]<=x[i]+d&&p<=n+1)p++;
			nxt[i]=p-1;
		}
		p=n;
		for(int i=n;i>=1;i--){
			while(x[p]>=x[i]-d&&p>=0)p--;
			pre[i]=p+1;
		}
		p=1;
		for(int i=1;i<=n;i++){
			while((nxt[i]-pre[p]>1&&p<=n)||p<=i+2)p++;
			if(nxt[i]-pre[p]==1&&p<=n){
				a[++cnt]=i;
				b[cnt]=p;
			}
		}
		b[cnt+1]=n+1;
		for(int i=1;i<=cnt;i++)ans+=(a[i]-max(a[i-1],l[a[i]]-1))*(min(b[i+1],r[b[i]]+1)-b[i]);
		cout<<ans<<endl;
	}
	return 0;
}
//16:48 ****!读错题了！
//17:17 maybe 做出了 O(n) 的正解。
//17:23 发现 -S 考 4 个小时而不是 3.5 个。
//17:24 发现椅子有靠背。
//17:29 测了一下心率，发现只有 91BPM。
//17:35 座位上的姓名贴掉下来了。
//17:51 有人告诉我们 T2 样例解释错了。
//17:59 ****!又做错了！
//18:28 AFO!NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!