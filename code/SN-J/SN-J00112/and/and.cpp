#include<bits/stdc++.h>
using namespace std;
int maxn=0;
int n,m,a[200005];
int yu(int x,int y){
	int sum=0;
	if(x%2!=0&&y%2!=0){
		sum+=1;
	}x/=2;
	y/=2;
	int c=1;
	while(x!=0){
		int t1=x%2,t2=y%2,a=1;
		if(t1!=0&&t2!=0){
			for(int i=1;i<=c;i++){
				a*=2;
			}
			sum+=a;
			c++;
		}else{
			c++;
		}
		x/=2;
		y/=2;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and,out","w",stdout);
	cin>>n>>m;
	int maxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(m==1){
		cout<<maxa;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,yu(a[i],a[j]));
			}
		}
		cout<<maxn;
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=i+2;k<=n;k++){
					int e=yu(a[i],a[j]);
					maxn=max(maxn,yu(a[k],e));
				}
			}
		}
		cout<<maxn;
	}
	return 0;
}
