#include<bits/stdc++.h>
using namespace std;
int n,i,t,w,bao,mid;
long long b[500100],m,c[500100],a[500100];
bool pd(int x){
	int i;
	long long s=0;
	for(i=2;i<=x;i++){
		s+=b[i]*(i-1);
	}if(s<=m){
		return 1;
	}for(i=x+1;i<=n;i++){
		s=s+x*b[i]-c[i]+c[i-x];
		if(s<=m){
			return 1;
		}
	}return 0;
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;t=1;w=n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		c[i]=c[i-1]+b[i];
	}while(t<=w){
		mid=(t+w)/2;
		if(pd(mid)){
			t=mid+1;
			bao=mid;
		}else{
			w=mid-1;
		}
	}cout<<bao;
	return 0;
}
