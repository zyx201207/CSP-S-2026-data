#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ma=max(a[i],ma);
		}
		cout<<ma;
	}else if(m==n){
		int ans;
		cin>>ans;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans&=a[i];
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		if(a[1]>=1&&a[n]<=4){
			int ax[6];
			for(int i=1,j=1;i<=n;i++){
				ax[j]++;
				if(a[i]!=a[i+1])j++;
			}
			if(ax[4]>=m)cout<<4;
			else if(ax[3]>=m)cout<<3;
			else if(ax[3]+ax[2]>=m)cout<<2;
			else if(ax[3]+ax[1]>=m)cout<<1;
			else cout<<0;
		}
		else cout<<a[n-m];
	}
	return 0;
}
