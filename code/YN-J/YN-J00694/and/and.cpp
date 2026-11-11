#include<bits/stdc++.h>
using namespace std;//见吾银枪白马，应知胜负已分！
int n,m;bool ok[200005];int a[200005],cnt[30],ans;
int main(){
	freopen("and.in","r",stdin),freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;for(int i=1;i<=n;i++){
		cin>>a[i];for(int j=0;j<30;j++)cnt[j]+=(a[i]&(1<<j))>>j;}
	for(int j=29;j>=0;j--)if(cnt[j]>=m){
		ans+=(1<<j);for(int i=1;i<=n;i++)if((!ok[i])&&(!(a[i]&(1<<j)))){ok[i]=1;for(int k=0;k<30;k++)cnt[k]-=(a[i]&(1<<k))>>k;}
	}cout<<ans;
	return 0;}
