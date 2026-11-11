#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],b[N],c[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	c[1]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	b[1]=0;
	long long i=1,j=1,maxt=0,t=1,ct=1,bow=0;
	int di=1,dj=1;
	while(j<=n){
		j++;
		int last=bow;
		bow+=t*c[j];
		if(bow<=m){
			t++;
			if(t>=maxt){
				maxt=t;
			}
		}else{
			bow=last;
			j--;
			i++;
			t--;
		}
	}
	cout<<maxt;
	return 0;
}	
