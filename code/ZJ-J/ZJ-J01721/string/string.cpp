#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010]={},sum=0,p,res=0,tmp=0;
char c[200010]={};
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	p=n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],sum+=a[i];
	for(int i=1;i<=n&&tmp<=sum;i++){
		tmp+=a[i];
		while(p>i&&a[i]){
			if(a[i]-a[p]>=0){
				if(c[i]!=c[p]) res+=a[p];
				tmp+=a[p];
				a[i]-=a[p];
				a[p]=0;
				p--;
			} 
			else{
				if(c[i]!=c[p]) res+=a[i];
				tmp+=a[i];
				a[p]-=a[i];
				a[i]=0;
				break;
			}
		}
 	}
	printf("%lld",res);
	return 0;
}
