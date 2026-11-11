#include<bits/stdc++.h>
using namespace std;
long long n,m,b[200005],bj[200005],a[200005],ans;
void o(){
	long long cnt=b[a[1]];
	for(int i=1;i<=m;i++){
		cnt&=b[a[i]];
	}
	ans=max(ans,cnt);
}
void dp(int c,int ma){
	if(c>m){
		o();
		return ;
	}
	for(a[c]=ma+1;a[c]<=n;a[c]++){
		if(bj[a[c]]==0){
			bj[a[c]]=1;
			dp(c+1,a[c]);
			bj[a[c]]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	dp(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
4 2
3 15 12 12
*/
