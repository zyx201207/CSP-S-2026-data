#include<bits/stdc++.h>
using namespace std;
long long a[201000],ma=0,mma=0,maa=0;
bool vis[201000];
int n,m;
void f(long long s,long long mm){
	if(mm==0){
		ma=max(ma,s);
	}
	for(int i=1;i<=n;i++){
		if(mm==m){
			vis[i]=1;
			f(a[i],mm-1);
			vis[i]=0;
		}else{
			if(!vis[i]){
				vis[i]=1;
				f((s&a[i]),mm-1);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			maa=a[i];
		}else{
			maa=(maa&a[i]);
		}
		mma=max(mma,a[i]);
	}
	if(m==1){
		cout<<mma;
		return 0;
	}else if(m==n){
		cout<<maa;
	}
	f(0,m);
	cout<<ma;
} 
