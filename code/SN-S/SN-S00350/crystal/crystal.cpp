//平晁宇 SN-S00350 西安铁一中滨河高级学校 
#include<bits/stdc++.h>
#define int long long
#define BF cout<<'\n'<<"---------------------"<<'\n';
using namespace std;
typedef pair<int,int> PII;


inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return w*s;
}

int n=0,m=0,ans=0;
int a[5000005],b[5000005];
int r=1,l=1,p=0,k=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	
	while(r<=n&&l<=r){
		while(p+(r-l+1)*(a[r+1]-a[r])<=m&&r<=n&&p>=0){
			r++;
			p=p+(r-l)*(a[r]-a[r-1]);
		}
		ans=max(ans,r-l+1);
		l++;
		p=p-(a[r]-a[l-1]);
	}
	
	cout<<ans;
	return 0;
}
