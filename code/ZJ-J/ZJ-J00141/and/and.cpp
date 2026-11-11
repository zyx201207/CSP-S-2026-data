#include<bits/stdc++.h>
using namespace std;
int a[200005],f[200005],b[200005][25],cnt[200005],ans[25];
void jz(int x,int h){
	int cnt1=0;
	while(x!=0){
		b[h][++cnt1]=x%2;
		x/=2;
	}
	cnt[h]=cnt1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		jz(a[i],i);
		sum=max(sum,cnt[i]);
	}
	for(int i=sum;i>=1;i--){
		int t=0;
		for(int j=1;j<=n;j++){
			if(b[j][i]==1&&f[j]==0) t++;
		}
		if(t>=m){
			ans[i]=1;
			for(int j=1;j<=n;j++){
				if(b[j][i]==0) f[j]=1;
			}
		}else{
			ans[i]=0;
		}
	}
	int d=0,b=1;
	for(int i=1;i<=sum;i++){
		d+=ans[i]*b;
		b*=2;
	}
	cout<<d;
	return 0;
}
