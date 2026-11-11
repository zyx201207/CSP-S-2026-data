#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200200],ans=0,k,sum,p[40];
bool cap(int q,int e){return q>e;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	k=n;
	p[0]=1;
	for(int i=1;i<=31;i++) p[i]=p[i-1]*2;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--){
		sort(a+1,a+1+k,cap);
		sum=0;
		for(int j=1;j<=k;j++){
			if((p[i]&a[j])!=0){
				sum++;
				a[j]-=p[i];
			}
		}
		if(sum>=m){
			k=sum;
			ans=(ans|p[i]);
		}
	}
	cout<<ans;
	return 0;
}
/*
5 3
31 3 1 15 7
*/
