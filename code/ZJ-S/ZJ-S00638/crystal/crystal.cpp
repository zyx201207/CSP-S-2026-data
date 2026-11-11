#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,m,ans,lg[N];
long long a[N],s[N],mx[N][25];
long long qmx(int l,int r){
	int x=lg[r-l+1];
	return max(mx[l][x],mx[r-(1<<x)+1][x]);
}
long long sum(int l,int r){
	return s[r]-s[l-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	int c=0;
	for(int i=1;i<=n;i++){
		if(i==(1<<(c+1)))c++;
		lg[i]=c;
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		mx[i][0]=a[i],s[i]=s[i-1]+a[i];
	for(int i=1;i<25;i++)
		for(int j=1;j<=n;j++){
			int mid=j+(1<<(i-1));
			if(mid>n)break;
			mx[j][i]=max(mx[j][i-1],mx[mid][i-1]);
		}
	for(int l=1,r=0;l<=n;l++){
		while(r<n&&qmx(l,r+1)*(r-l+2)-sum(l,r+1)<=m)r++;
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
}
//AKIOI!
