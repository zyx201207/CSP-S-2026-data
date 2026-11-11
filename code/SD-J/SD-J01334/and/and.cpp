#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx;
void f(int i,int sum,int step){
	if(step==m){
		maxx=max(maxx,sum);
		return;
	}
	for(int j=i+1;j<=n-m+step+1;j++){
		f(j,sum&a[j],step+1);
	}
	return;
}
bool cmp(int x,int y){
	return x>y;
}
int P[21]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		int s=0;
		for(int k=0;k<=20;k++){
			if(a[i]==P[k]-1){
				s=1;
			}
		}
		A=min(A,s);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=a[i]&a[i-1];
		}
		cout<<a[n];
		return 0;
	}
	if(A){
		sort(a+1,a+n+1,cmp);
		for(int i=2;i<=m;i++){
			a[i]=a[i]&a[i-1];
		}
		cout<<a[m];
		return 0;
	}
	if(maxx<=2000){
		maxx=0;
		for(int i=1;i<=n-m+1;i++){
			f(i,a[i],1);
		}
		cout<<maxx;
	}
	return 0;
}
