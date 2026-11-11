#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5;
LL a[N],m,x[N];
int n;
LL pre[N];
LL ans=1LL;
bool f=true;
void fun1(){
	pre[0]=0LL;
	for(int i=1;i<=n;i++){
		pre[i]=x[i];
		pre[i]+=pre[i-1];
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			LL len=(LL)r-(LL)l+1LL;
			if(pre[r]-pre[l-1]-((LL)r-(LL)l+1LL)*(a[n]-a[r])<=m){
				ans=max(len,ans);
			}
		}
	}
	cout<<ans;
	return ;
}
void fun2(){
	LL d=a[2]-a[1];
	LL n2=(LL)n;
	for(int i=1;i<=n2;i++){
		LL num=((LL)i)*((LL)i-(1LL))/(2LL);
		if(d*i*(i-(1LL))/(2LL)>=m){
			ans=max(ans,num);
		}
	}
	cout<<ans;
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		x[i]=a[n]-a[i];
	}
	for(int i=2;i<n;i++){
		if(a[i+1]+a[i-1]==a[i]+a[i]){
			f=false;
			break;
		}
	}
	if(n<=5000){
		fun1();
	}else if(f){
		fun2(); 
	}
	
	return 0;
}