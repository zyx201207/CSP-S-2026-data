#include<bits/stdc++.h>
#define LL long long  
using namespace std;

const int N=3e5+10;
LL n;
struct node{
	LL x;
	char y;
}a[N];
LL ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(LL i=1;i<=n;i++){
    	cin>>a[i].x>>a[i].y;
	}
	LL l=1,r=n;
	while(l<r){
		if(a[l].y!=a[r].y){
			ans+=min(a[r].x,a[l].x);
		}
		if(a[l].x>a[r].x){
			a[l].x-=a[r].x;
			r--;
			
		}else if(a[l].x<a[r].x){
			a[r].x-=a[l].x;	
			l++;
		}else if(a[l].x==a[r].x){
			l++;
			r--;	
		}
		
	} 
	cout<<ans;
	return 0;
}
