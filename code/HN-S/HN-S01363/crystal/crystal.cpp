#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],t=0,ans=0,ans1=0,q=0,e=0;
void ss(int x,int y){
	if(x==y){
		return ;
	}
	if(y>n){
		return ;
	}
	if(x>n){
		return ;
	}
	int t=m;
    for(int i=x;i<y;i++){
    	if(b[y]-b[i]<=t){
    		b[i]=b[y];
    		t-=b[y]-b[i];
		}
		else{
			break;
		}
	}
		
		for(int i=1;i<=n-1;i++){
    	if(b[i]==b[i+1]){
    		ans++;
		}
	else{
		ans1=max(ans,ans1);
		ans=0;
	}
}
    for(int i=1;i<=n;i++){
    	b[i]=a[i];
	}
	ss(x-1,y);
	ss(x,y+1);
}
int main(){
	
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
    b[i]=a[i];
	}
	ss(1,2);
	for(int i=1;i<=n-1;i++){
		if(a[i+1]-a[i]==1){
			q++;
		}
		e+=a[n]-a[i];
	}
	if(q==n-1 and e>m){
		cout<<ans1;
		return 0;
	}
	cout<<ans1+1;
	return 0;
} 
