#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],d[500005],q[500005],ans=0,tmp,j,f=1;
signed main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	d[0]=0;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
		if(i!=0){
			d[i]=a[i]-a[i-1];
			q[i]=d[i]+q[i-1];
		}
	for(int i=2;i<n-1;i++)
		if(d[i]-d[i-1]!=d[i+1]-d[i])f=0;
	if(f){
		int dis=d[1],temp=1;
		while(1){
			if(m>=temp*dis)m-=temp*dis;
			else break;
			temp++;
		}
		cout<<temp;
		return 0;
	}
	for(int i=n/2;i<n;i++){
		tmp=m;
		for(j=i-1;j>=1;j--){
			if(tmp<(q[i-1]-q[j-1]))break;
			tmp-=q[i-1]-q[j-1];
		}
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}
