#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],b[N],c[N],ans=0; 
long long sum(int l,int r){
	int tot=0;
	for(int i=r-1;i>=l;i--){
		tot+=a[r]-a[i];
	}
	return tot;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	n=500005;
	m=10;
	for(int i=500005;i>0;i--){
		a[i]=i;
	}
	c[1]=1;
	sort(a,a+n);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	b[1]=0;
	long long i=1,j=1,maxt=0,t=1,ct=1,bow=0;
	int di=1,dj=1;
	while(j<=n){
		j++;
		long long last=bow;
		bow+=t*c[j];
		if(bow<=m){
			t++;
			if(t>=maxt){
				maxt=t;
				di=i,dj=j;
			}
		}else{
			bow=last;
			j--;
			i++;
			t--;
		}
	}
	cout<<di<<endl;
	cout<<maxt;
	return 0;
}
