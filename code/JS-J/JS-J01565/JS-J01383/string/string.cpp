#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
char d[N];
int q[N],t;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i]>>d[i];
		q[i]+=q[i-1];
	}
	t=q[n];
	int sum=0,now=1,xian=1,fnow=t,fxian=n;
	char zi=d[1],fzi=d[n];
	while(now<=t/2){
		if(now>q[xian]){
			xian++;
			zi=d[xian];
		}
		if(fnow<q[xian]){
			fxian--;
			fzi=d[fxian];
		}
		if(zi!=fzi) sum++;
		now++;
		fnow--;
	}	
	cout<<sum;
	return 0;
}
