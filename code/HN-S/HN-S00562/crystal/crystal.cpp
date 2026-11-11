#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[5086],b,c,d[5086],maxn=-1;
ll m,e;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1]>>a[2];
	c=a[2]-a[1];
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(c==a[i]-a[i-1]&&b==0){
			continue;
		}
		else  b=1; 
	}
	if(b==0){
		for(int i=1;i<=n;i++){
			b++;
			m-=c*i;
			if(m<0)break;
		}
		cout<<b;
		return 0;
	}
	c=0;b=0;
	for(int i=1;i<=n;i++){
		memset(d,0,sizeof(d));
		for(int j=1;j<=i;j++){
			d[j]=a[i]-a[j];
		}
		e=m;
		c=0;
		for(int j=i;j>=1;j--){
			c++;
			e-=d[j];
			if(e<0){
				maxn=max(maxn,c);
				break;
			}
		} 
		maxn=max(maxn,c);
	}
	cout<<maxn;
	return 0;
} 
