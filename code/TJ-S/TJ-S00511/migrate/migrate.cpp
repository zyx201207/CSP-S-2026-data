#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,d;
long long a[2000005]={},cnt;
long long b[2000005]={};
bool lian(int u,int v){
	int j=0;
	for(int i=v-1;i>u;i--){
		if((a[v]-a[i])<=d){
			j++;
			b[j]=a[i];
		}else{
			break;
		}
	}
	sort(b+1,b+j);
	int now=a[u],i=u;
	while(now<a[v]){
		int cnt=0;
		for(int k=1;k<=j;k++){
			if(a[k]-now<=d){
				cnt++;
			}
		}
		if(cnt!=0){
			if(cnt!=2){
				return 0;
			}
			if(cnt==2){
				return 1;
			}
			
		}
		for(int k=v;k>i;k--){
			if(a[k]-now<=d){
				now=a[k];
				i=k;
				break;
			}
		}
	}
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>d;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(lian(i,j)){
					cnt++;
				}
			}
		}
		cout<<cnt;
	}
	return 0;
}
