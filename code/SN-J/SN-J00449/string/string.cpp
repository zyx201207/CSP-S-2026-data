#include<bits/stdc++.h>
using namespace std;
long long cnt,a[200010],n,ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	cnt/=2;
	long long j=1,jj=n;
	while(cnt>0){
		if(a[j]==0){
			j++;
		}
		if(a[jj]==0){
			jj--;
		}
		if(c[j]!=c[jj]){
			if(a[j]>a[jj]){
				ans+=a[jj];
				a[j]-=a[jj];
				cnt-=a[jj];
				a[jj]=0;
			}else if(a[j]==a[jj]){
				ans+=a[j];
				cnt-=a[jj];
				a[jj]=0;
				a[j]=0;
			}
			else{
				ans+=a[j];
				a[jj]-=a[j];
				cnt-=a[j];
				a[j]=0;
			}
		}else{
			if(a[j]>=a[jj]){
				a[j]-=a[jj];
				cnt-=a[jj];
				a[jj]=0;
			}else{
				a[jj]-=a[j];
				cnt-=a[j];
				a[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
