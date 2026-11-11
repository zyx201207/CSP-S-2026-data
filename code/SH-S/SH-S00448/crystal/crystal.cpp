#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
int N,M,a[MAXN],dif[MAXN],pre[MAXN],Ans;
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+N);
	for(int i=1;i<=N;i++){
		dif[i]=a[i]-a[i-1];
		pre[i]=pre[i-1]+dif[i];
	}
	int l=1,r=0,cnt=0;
	while(l<=N){
		while((r+1)<=N){
			r++;
			cnt+=(r-l)*dif[r];
			if(cnt>M)break;
			Ans=max(Ans,r-l+1);
		}
		if(r==N)break;
		while(l<=N&&cnt>M){
			cnt-=pre[r]-pre[l];
			l++;
		}
	}
	cout<<Ans<<endl;
	return 0;
}
