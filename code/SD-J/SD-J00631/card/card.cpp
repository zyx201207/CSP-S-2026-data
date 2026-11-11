#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],sum[600000];
long long zhan[600000],t,boo[600000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int o=1;o<=n;o++){
		t=1;
		memset(zhan,0,sizeof(zhan));
		memset(boo,0,sizeof(boo));
		for(int i=o;i<=n;i++){
			if(boo[a[i]]==0||boo[a[i]]>t-1){
				boo[a[i]]=t;
				zhan[t]=a[i];
			}
			else{
				t=boo[a[i]];
			}
			t++;
		}
		for(int i=1;i<t;i++){
			sum[zhan[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}

