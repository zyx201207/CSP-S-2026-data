#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+5;
long long n,m,a[N],b[N],l,r,f,sum=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]<0){
		f=0-a[1];
		for(int i=1;i<=n;i++) a[i]+=f;
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1,j=1;i<=n&&j<=n;){
		if(a[j]*(j-i+1)-(b[j]-b[i-1])<=m){
			sum=max(sum,j-i+1ll);
			j++;
		}else{
			i++;
		}
	}
	cout<<sum;
	return 0;
}
