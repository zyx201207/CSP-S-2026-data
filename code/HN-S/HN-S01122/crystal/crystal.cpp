#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int ans=-1e9,sub[N],pr[N],pre[N],a[N],n,m;
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n,cmp);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		sub[i]=a[i]-a[i-1];
		pr[i]=pr[i-1]+sub[i];
		pre[i]=pre[i-1]+(sub[i]*(i-1));
	} 
//	for(int i=1;i<=n;i++){
//		cout<<pre[i]<<" ";
//	}
	int j=1;
	for(int i=1;i<=n;i++){
		if(pre[i]-((a[i]-a[j-1])*(j-1)+pre[j-1])>m){
			j++;
		}else{
			ans=max(ans,i-j+1) ;
//			printf("i is %d  j is %d  ans is %d\n",i,j,ans); 
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5 
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
//%%%Ô¬×Ünb 
