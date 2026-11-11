#include<iostream>
using namespace std;
long long a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
	}
	maxn=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				maxn=max(a[i]&a[j],maxn);
			}
		}
		cout<<maxn;
	}
	maxn=0;
	if(m==n-1&&m!=2){
		
		for(int i=1;i<=n;i++){
		long long cnt=8589934591;
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				cnt&=a[j];
			}
			maxn=max(cnt,maxn);
		}
		cout<<maxn;
		
	}
	return 0;
}
