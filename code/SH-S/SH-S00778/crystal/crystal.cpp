#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[500005],c[500005];
ll m,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ff=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) ff=1;
	}
	if(ff==0){
		for(int i=1;i<=m;i++){
			if(m>=i){
				m-=i;
				ans++;
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		memset(c,0,sizeof(c));
		ll anss=0;
		for(int j=1;j<=i;j++){
			c[j]=a[i]-a[j];
		}
		sort(c+1,c+i);
		int cnt=0,in=1;
		while(cnt<=m&&in<=i){
			if(m-cnt>=c[in]){
				anss++;
				cnt+=c[in];
				in++;
			}
			else break;
		}
		ans=max(ans,anss);
	}
	cout<<ans;
	return 0;
}
