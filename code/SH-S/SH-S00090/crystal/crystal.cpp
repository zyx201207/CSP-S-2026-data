#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n;
long long m;
long long a[MAXN];
long long b[MAXN];
int ans[MAXN];//如果i号水晶是参与合成的最小水晶，最多可以合成到第ans[i]号水晶 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//a[i]=a[i]+1e12;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	
	ans[1]=1;
	for(long long i=1;i<=n;i++){
		if(i*a[i]-b[i]<=m){
			ans[1]=i;
		}else{
			break;
		}
	}
	//long long s=ans[1]*a[ans[1]]-b[ans[1]];
	for(int i=2;i<=n;i++){ //i号水晶是参与合成的最小水晶
		ans[i]=ans[i-1];
		//s-=a[ans[i]-1]-a[i]; 
		for(int j=ans[i-1]+1;j<=n;j++){//j从上一轮第一个不被合成的水晶开始 
			/*s+=(a[j]-a[j-1])*(j-i+1);
			if(s>m){
				ans[i]=j-1;
				break;
			}else{
				ans[i]=j;
			}*/
			if(a[j]*(j-i+1)-(b[j]-b[i-1])<=m){
				ans[i]=j;
			}else{
				break;
			}
		}
		if(ans[i]==n){
			break;
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(ans[i]-i+1,maxx);
	}
	cout<<maxx;
	return 0;
} 
