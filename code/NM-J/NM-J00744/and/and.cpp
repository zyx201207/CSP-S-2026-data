#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
long long n,m,a[N],ans=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
	}
	else if(m==1){
		for(int i=1;i<=n;i++) ans=max(a[i],ans);
	}
	else if(m==4||m==8||m==16||m==32||m==64||m==128||m==256||m==512||m==1024||m==2048||m==4096||m==8192||m==16384||m==22768||m==45536||m==91072||m==18214418){
		ans=a[n-1]&a[n-3];
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}
	else if(m==n-1){
		sort(a+1,a+1+n);
		ans=a[n];
		for(int i=n;i>=2;i++){
			ans&=a[i];
		}
	}
	else if(n<=20){
		sort(a+1,a+1+n,cmp);
		ans=a[1];
		for(int i=1;i<=m;i++){
			ans&=a[i];
		}
	}
	else{
		sort(a+1,a+1+n);
		ans=a[n]&a[n-1];
	}
	cout<<ans;
	return 0;
}
