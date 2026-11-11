#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
const int N=2e6+10;
int a[N],pre[N],suf[N];
vector<int> l1,l2;
void work(int c){
	int n=read(),k=read(),ans=0;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1,j=1;i<=n;i++){
		while(j<n&&a[j+1]-a[i]<=k) j++;
		suf[i]=j;
	}
	for(int i=n,j=n;i>=1;i--){
		while(j>1&&a[i]-a[j-1]<=k) j--;
		pre[i]=j;
	}
	if(c==0||c==11||c==12){
		int d=k/(a[2]-a[1]);
		for(int i=1;i<=n;i++) ans+=max(min(n+1,i+2*d)-min(n+1,i+2*d-2)-1,0ll);
		if(d<=1) ans=0;
		cout <<ans<<"\n";
		for(int i=1;i<=n;i++) a[i]=pre[i]=suf[i]=0;
		return; 
	}
	// for(int i=1;i<=n;i++) cout <<pre[i]<<" ";
	// cout <<"\n";
	// for(int i=1;i<=n;i++) cout <<suf[i]<<" ";
	// cout <<"\n";
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			l1.clear(),l2.clear();
			int l=i,len=0,flag=1;
			while(l<j){
				l1.push_back(l);
				if(l==suf[l]){
					flag=0;
					break;
				}
				else l=suf[l];
			}
			if(!flag) continue;
			l1.push_back(j),l=j;
			len=l1.size();
			while(l>i) l2.push_back(l),l=pre[l];
			l2.push_back(i);
			reverse(l2.begin(),l2.end());
			// for(auto k:l1) cout <<k<<" ";
			// cout <<"\n";
			// for(auto k:l2) cout <<k<<" ";
			// cout <<"\n";
			int cnt=0;
			// cout <<len<<"\n";
			for(int k=0;k<len;k++){
				if(l1[k]!=l2[k]&&abs(l1[k]-l2[k])==1){
					cnt++;
					if(cnt>1){
						flag=0;
						break;
					}
				}
				else if(l1[k]!=l2[k]){
					flag=0;
					break;
				}
			}
			if(cnt==0) flag=0;
			ans+=flag;
			// if(flag) cout <<i<<" "<<j<<"\n";
			// cout <<cnt<<" "<<flag<<"\n\n";
		}
	}
	cout <<ans<<"\n";
	for(int i=1;i<=n;i++) a[i]=pre[i]=suf[i]=0;
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),t=read();
	while(t--) work(c);
	return 0;
}