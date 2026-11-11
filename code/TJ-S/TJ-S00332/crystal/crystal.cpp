#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500004],t[500004];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(t,0,sizeof(t));
	int n,m;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int lmax=a[1],xb=1;
		for(int j=2;j<=n;j++){
			if(a[j]<lmax){
				int temp=a[j];
				a[j]=lmax;
				a[xb]=temp;
				xb=j;
			}else{
				xb=j;
				lmax=a[j];
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		t[i]=1;
		int g=m;
		
		if(a[i]==a[i-1] && i>1){
			t[i]=t[i-1]+1;
			continue;
		}
		
		for(int j=i-1;j>=1;j--){
			g-=(a[i]-a[j]);
			if(g<0){
				continue;
				j=0;
			} else{
				t[i]++;
			}
		}
	}
	
	int max=0;
	for(int i=1;i<=n;i++){
		if(t[i]>=max) max=t[i];
	}
	printf("%lld\n",max);
	
	return 0;
} 
