#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=INT_MAX,ans1=INT_MAX,ones[32],maxx;
bool cmp(int a,int b){return a>b;}
void changeto2(int x){
	int pos=0;
	while(x){
		if(x&1) ones[pos]++;
		pos++; x>>=1;
	}
}
bool avai[32];
bool check(int x){
	int pos=0;
	while(x){
		if((x&1)&&avai[pos]) return true;
		pos++; x>>=1;
	}
	return false;
}
int main(){
	freopen("and4.in","r",stdin);
	//~ freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i]; changeto2(a[i]);}
	for(int i=31;i>=0;i--){
		if(ones[i]<m) avai[i]=0;
		else avai[i]=1;
	}
	//~ for(int i=0;i<31;i++) cout<<ones[i]<<' ';
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++) ans1&=a[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt==m) break;
		//~ cout<<a[i]<<' '<<check(a[i])<<'\n';
		if(check(a[i])) ans&=a[i],cnt++;
	}
	//~ cout<<max(ans1,ans);
	cout<<ans;
	return 0;
}
