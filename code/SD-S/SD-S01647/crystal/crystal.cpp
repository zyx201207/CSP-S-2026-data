#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],cf[500005],qz[500005],tp,len=1,pos=1,maxx=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	tp=m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) cf[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++) qz[i]=qz[i-1]+cf[i];
	for(int i=1;i<n;i++){
		if(cf[i]*len<=m) m-=cf[i]*len,len++,maxx=max(maxx,len);
		else{
			while(len>1&&m<cf[i]*len) len--,m+=qz[i-1]-qz[pos-1],pos++;
			if(len==1) m=tp,len=1,pos=i;
			else m-=cf[i]*len,len++;
		}
	}
	cout<<maxx;
	return 0;
}
//qwq
