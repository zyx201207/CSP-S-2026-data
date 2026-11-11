#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],sum,ans,cnt;
char c[1000005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		cnt++;
	}
	int si=0,sj=0;
	int i=1,j=cnt;
	for(;si<=sum/2,sj<=sum/2,i<j;){
		
		if(a[i]>a[j]){
			if(c[i]!=c[j]){
				ans+=a[j];
			}
			si+=a[j];
		    sj+=a[j];
			a[i]-=a[j];
			j--;
		}else if(a[i]<a[j]){
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			si+=a[i];
		    sj+=a[i];
			a[j]-=a[i];
			i++;
		}else if(a[i]==a[j]){
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			si+=a[i];
		    sj+=a[i];
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
