#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int xa[N],xb[N];
char ca[N],cb[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>xa[i]>>ca[i];
		xb[n-i+1]=xa[i];
		cb[n-i+1]=ca[i];
	}
	int pa=0,pb=0;
	long long wa=0,wb=0,ans=0;
	while(1){
		if(pa==n&&pb==n&&wa==0&&wb==0)break;
		if(wa==0){
			pa++;
			wa=xa[pa];
		}
		if(wb==0){
			pb++;
			wb=xb[pb];
		}
		long long ctmd=min(wa,wb);
		if(ca[pa]!=cb[pb])ans+=ctmd;
		wa-=ctmd;
		wb-=ctmd;
	}
	ans/=2; 
	cout<<ans;
	return 0;
}
