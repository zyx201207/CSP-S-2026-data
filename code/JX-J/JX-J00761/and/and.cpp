#include<bits/stdc++.h>
using namespace std;
const int Maxn=2e5+5;
int n,m;
int mm=-1;
int a[Maxn];
int jz(int a,int x){
	int b[35]={0},y[35]={0};
	int l=1,r=1;
	while(a>=2){
		b[l]=a%2;
		a=a/2;
		l++;
	}
	while(x>=2){
		y[l]=x%2;
		x=x/2;
		r++;
	}
	int ans=0;
	for(int i=min(l,r);i>=1;i--){
		if(b[i]==y[i]){
			ans+=pow(2,min(l,r)-i);
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mm=max(mm,jz(a[i],a[j]));
		}
	}
	cout<<mm;
	return 0;
}
