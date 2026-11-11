#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a[i-1]=a[i]+a[i-1];
			i--,n--;
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<"   "<< c[i];
//	}
	for(int i=1,j=n;i<=n && j>=1 && i<=j;i++,j--){
		if(j-i<=1 && c[i]!=c[j]){
			cnt+=min(a[i],a[j]);
		}else if(j-i<=1 && c[i]!=c[j]){
			;
		}else if(c[i]!=c[j]){
			if(a[j]==a[i]){
				c[i]=c[j];
				cnt+=a[i];
			}else if(a[i]>a[j]){
				cnt+=abs(a[i]-a[j]);
				a[i]=a[i]-a[j];
				i--;
			}else{
				cnt+=abs(a[j]-a[i]);
				a[j]=a[j]-a[i];
				j++;
			}
		}else if(c[i]==c[j] && a[i]!=a[j]){
			if(a[i]<a[j]){
				a[j]=a[j]-a[i];
				j++;
			}else{
				a[i]=a[i]-a[j];
				i--;
			}
		}
	}
	printf("%lld",cnt);
	
	return 0;
}
