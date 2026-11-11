#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	LL n,m;
	cin>>n>>m;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    sort(a+1,a+n+1);
    
    if(abs(a[n])>100000){
    	LL gc=a[2]-a[1];
    	LL cnt=0,p=0,sum=0;
    	while(1){
    		sum+=p*gc;
    		if(sum>m) break;
    		cnt++;
    		if(sum==m) break;
    		p++;
		}
		if(cnt>n) cout<<n;
		else cout<<cnt;
		return 0;
	}
	
	LL mina=a[1],maxa=a[n],ans=-1;
	for(int i=mina;i<=maxa;i++){
		int p;
		for(int j=1;j<=n;j++){
			if(a[j]>i){
				p=j-1;
				break;
			}
		    if(j==n){
				p=j;
				break;
			}
		} 
		LL mm=m,cnt=0;
		while(1){
			mm-=i-a[p];
			cnt++;
			if(mm<0) cnt--;
			if(mm<=0) break;
			p--;
			if(p==0) break;	
		}
		if(cnt>ans) ans=cnt;
	}
	cout<<ans;
	return 0;
}