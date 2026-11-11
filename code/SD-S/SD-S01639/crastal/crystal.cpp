#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010]={0},b[500010]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[n+1]=a[n];
	for(int i=1;i<=n;i++){
		a[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int r=1,l=1,en=0,ans=0;
	while(r+1<=n){
		r++;
		en+=(r-l)*a[r-1];
		cout<<l<<" "<<r<<":"<<en<<endl;
		if(en>m){
			l++;
			en-=b[r]-b[l];
		}else{
			ans=max(r-l+1,ans);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
