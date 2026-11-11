#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int m,n,a[N],ans,f=1,cnt,x=1,amx,p;
bool cmp(int x,int y){
	return x>y;
}
bool ck(int x){
	x+=1;
	while(x>=2){
		if(x==2) return true;
		x/=2;
		if(x%2==1) return false;
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	else if(m==2){
		if(m==n){
			cout<<(a[1]&a[2]);
			return 0;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ans=a[i];
					ans=ans&a[j];
					amx=max(amx,ans);
				}
			}
			cout<<amx;
			return 0;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(ck(a[i])!=true) f=0;
		}
		if(f==1) cout<<a[m];
	}
	return 0; 
}
