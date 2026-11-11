#include<bits/stdc++.h>
using namespace std;
#define PID "crystal"
#define FI freopen(PID".in","r",stdin);
#define FO freopen(PID".out","w",stdout);
const int N=5e5+10;
long long n,m,a[N],cnt[N],ans;
int main(){
	FI;FO;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long r=1,c;
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1]+(a[i]-a[i-1])*(i-1);
		if(i==1){
			ans=1;
		}else{
			while(true){
				c=cnt[i]-cnt[r-1]-(a[i]-a[r-1])*(r-1);
				if(c>m){
					r++;
				}else if((cnt[i]-cnt[r-2]-(a[i]-a[r-2])*(r-2))>m||r==1){
					break;
				}else{
					r--;
				}
			}
			ans=max(ans,i-r+1);
		}
	}
	cout<<ans;
	return 0;
}
