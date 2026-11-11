#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,ans[N],t[N],a[N],b[N];  //ans:答案  t[i]:点数为i的牌曾在t[i]出现过  b[i]:第i局结尾牌 
bool f[N];  //f[i]:点数为i的牌是否出现过 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		memset(f,0,sizeof f);
		memset(t,0,sizeof t);
		
		f[a[i]]=1;
		t[a[i]]=1;
		int cnt=2;
		b[1]=a[i];
		for(int j=i+1;j<=n;j++){
			if(f[a[j]]==0){
				b[++cnt]=a[j];
				f[a[j]]=1;
				t[a[j]]=cnt;
			}
			else{
				int w=t[a[j]];
				for(int k=1;k<=w;k++)
					b[k]=-1;
				b[++cnt]=a[j];
				t[a[j]]=cnt;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]!=0 && b[i]!=-1)ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
