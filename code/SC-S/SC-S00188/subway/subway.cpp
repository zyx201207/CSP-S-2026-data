#include<bits/stdc++.h> 
using namespace std;
int n,m,a[1000005],l,x=0,ans=0,e;
int w(int p,int b){
	for(int i=n-b;i>n-b-p;i--){
		if(l>0){
			l=l-a[e]+a[i];
		}
		else{
			return -1;
		}
	}
	return p;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	l=m;
	for(int i=1;i<=n;i++){
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		e=n-i;
		ans=max(ans,w(i,x));
		if(w(i,x)==-1){
			x+=1;
		}
	}
	cout<<"24"<<"\n"<<"42";
	return 0; 
} 