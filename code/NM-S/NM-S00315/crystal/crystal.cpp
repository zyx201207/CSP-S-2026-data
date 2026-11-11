#include<bits/stdc++.h>
using namespace std;
const int N=1e6+50;
int a[N],c[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i]+c[i-1];
		b[i]=c[i]-a[i];
	}
	for(int i=n;i>=1;i--){
		int st=m;
		int sum=1;
		int j=1;
		while(st>0){
			if(i-j<1) break;
			if(b[i]-b[i-j]>st){
				break;
			}
			else{
				st-=b[i]-b[i-j];
				sum++;
			}
			j++;
		}
		if(sum>maxn) maxn=sum;
	}
	cout<<maxn;
	return 0;
}
