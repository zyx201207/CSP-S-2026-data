#include<bits/stdc++.h>
using namespace std;
int maxx=-1;
long long a[1000005],n,m;
long long check(int g){
	int cnt=0;
	long long f;
	int w=0;
	bool flag=false;
	bool r[100000]={};
	while(g){
		w++;
		if(g%2==1){
			r[w]=1;
			cnt++;
		}else r[w]=0;
		g/=2;
	}
	if(cnt!=m) return -1;
	for(int i=1;i<=n;i++){
		if(r[i]){
			if(!flag){
				f=a[i];
				flag=true;
			}else f&=a[i];
		}
	}
	return f;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=9999;i++){
		if(check(i)>maxx) maxx=check(i);
	}
	cout<<maxx;
	return 0;
}
