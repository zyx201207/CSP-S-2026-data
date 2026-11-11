#include<bits/stdc++.h>
#define int long long
#define N 200010
using namespace std;
int n,m,maxn;
int a[N][35],edges[N],c[N];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b%2==1){
			res*=a;
		}
		a=a*a;
		b/=2;
	}
	return res;
}
int cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		int x=c[i];
		int cnt=1;
		while(x){
			if(x%2==0){
				a[i][cnt]=0;
				cnt++;
			}
			else{
				a[i][cnt]=1;
				cnt++;
			}
			x/=2;
		}
		if(cnt>=maxn){
			maxn=cnt;
		}
	}
	int ans=0,n1=n;
	for(int i=maxn-1;i>=1;i--){
		int flag=0;
		for(int j=1;j<=n;j++){
			if(edges[j]==1) continue;
			if(a[j][i]==0&&n1>m){
				edges[j]=1;
				n1-=1;
			}
			if(a[j][i]==1){
				flag++;
			}
		}
		if(flag>=m){
			ans+=ksm(2,i-1);
		}
	}
	cout<<ans;
	return 0;
}