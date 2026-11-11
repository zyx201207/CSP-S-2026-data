#include <bits/stdc++.h>
using namespace std;
int t[25],sum;
bool cmp(int x,int y){
	return x>y;
}
int andd(int p,int q){
	for(int i=1;i<=25 && p!=0 && q!=0;i++){
		if(p%2==1 && q%2==1)t[i]=1;
		else t[i]=0;
		p/=2;
		q/=2;
	}
	sum=0;
	for(int i=1;i<=22;i++){
		sum+=t[i]*pow(2,i-1);
		t[i]=0;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[2010];
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m-1;i++){
		sum=andd(a[i],a[i+1]);
		a[i+1]=sum; 
	}
	cout << sum;
	return 0;
}