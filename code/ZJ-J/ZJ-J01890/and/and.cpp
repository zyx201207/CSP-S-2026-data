#include<bits/stdc++.h>
using namespace std;
int n,m,x,j,cnt,ans,now,len,c[200005],a[200005],f[35];
bool g[200005];
void ban(int k){
	for(int i=1;i<=n;i++)
		if((!g[i])&&(!((a[i]>>k)&1))){
			g[i]=true;
			x=a[i],j=0;
			while(x){
				f[j]-=x&1;
				x>>=1;
				j++;
			}
			now--;
		}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=a[i],j=0;
		while(x){
			f[j]+=(x&1);
			x>>=1;
			j++;
		}
	}
	now=n;
	ans=0x7fffffff;
	for(int i=30;i>=0;i--){
		if(f[i]<m)continue;
		ban(i); 
		if(now<m){
			cout<<i<<'\n';
			break;
		}
	}
	for(int i=1;i<=n;i++)
		if(!g[i])
			c[++len]=a[i];
	sort(c+1,c+1+len);
	for(int i=len;i>len-m;i--)
		ans&=c[i];
	cout<<ans;
	return 0;
} 
