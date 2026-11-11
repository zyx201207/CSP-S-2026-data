#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
ll sum[500010],cha[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+cha[i]*(i-1);
	}
	if(m==0){
		int num=1,mx=-1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				num++;
			}else{
				mx=max(num,mx);
				num=1;
			}
		}
		mx=max(mx,num);
		cout<<mx<<"\n";
		return 0;
	}
	ll mxlen=-1;
	ll l=1,r=2,len=2;
	ll tmp=sum[2];
	for(int i=2;i<=n;i++){
		while(tmp>m){
			tmp-=(a[r]-a[l]);
			l++;
			len--;
		}
		if(tmp<=m){
			mxlen=max(len,mxlen);
			len++;
			r++;
			tmp+=(a[r]-a[r-1])*(len-1);
		}
	}
	cout<<mxlen<<"\n";
	return 0;
}
