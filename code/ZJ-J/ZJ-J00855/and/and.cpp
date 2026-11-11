#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,s,cnt,cnt_2,a[40],d[200010],c[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    a[0]=1;
    for(int i=1;i<=30;i++)a[i]=a[i-1]*2;
    for(int i=1;i<=n;i++)cin>>d[i];
    cnt_2=n;
    for(int j=30;j>=0;j--){
    	cnt=0;
    	for(int i=1;i<=cnt_2;i++)
		    if((a[j]&d[i])!=0)cnt++,c[cnt]=d[i];
		if(cnt==m){
			ans=c[1];
			for(int i=2;i<=cnt;i++)ans=(ans&c[i]);
			cout<<ans;
			return 0;
		}
		else if(cnt>m){
			s+=(1<<j);
			for(int i=1;i<=cnt;i++)d[i]=c[i];
			cnt_2=cnt;
		}
	}
    cout<<s;
	return 0;
}
