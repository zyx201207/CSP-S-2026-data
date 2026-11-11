#include<bits/stdc++.h>
using namespace std;
int n,m,f,maxx,ans,a[200005];
void solver(){
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans&a[i];
	}
}
void solver1(int x,int y,int z){
	if(y==0){
		ans=max(ans,z);
		return ;
	}
	if(x<=0){
		return ;
	}
	solver1(x-1,y,z);
	solver1(x-1,y-1,(z&a[x]));
}
void solver2(){
	if(m==2){
		ans=n-2;
	}
	else if(m<=n/2){
		ans=n/2;
	}
	else{
		ans=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(a[i]==i-1){
			f++;
		}
	}
	if(m==n){
		solver();
	}
	else if(m==1){
		ans=maxx;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else if(n<=20){
		solver1(n,m,(1<<30)-1);
	}
	else if(f==n){
		solver2();
	}
	else{
		ans=0;
	}
	cout<<ans<<endl;
	return 0;
}
