#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,a[200005];
char c[200005];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}int l=1,r=n;
	int xs=a[l],ys=a[r];
	while(l<=r){
		int maxx=max(xs,ys),minn=min(xs,ys);
		if(c[l]!=c[r]){
			sum+=minn;
		}if(maxx==xs){
			xs-=ys;
			ys=0;
		}else{
			ys-=xs;
			xs=0;
		}
		if(xs==0){
			l++;
			xs=a[l];
		}if(ys==0){
			r--;
			ys=a[r];
		}
	}cout<<sum;
	return 0;
}
