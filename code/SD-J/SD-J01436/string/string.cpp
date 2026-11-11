#include<bits/stdc++.h>
using namespace std;
struct N{
	long long x;
	char y; 
}a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,o,r;
	long long cc=0,c=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		c+=a[i].x;
	} 
	for(int i=1;i<=n;i++){
		cc+=a[i].x;
		if(cc>=(c+1)/2){
			if(c%2!=0){
				a[i].x--;
			}
			if(cc-(c+1)/2>=a[i].x-(cc-(c+1)/2)){
				o=i-1;
				a[i].x=cc-(c+1)/2-(a[i].x-(cc-(c+1)/2));
			}
			else{
				o=i;
				a[i].x=(a[i].x-(cc-(c+1)/2))-(cc-(c+1)/2);					
			}
			break;
		}
	} 		
	r=n;
	for(int i=1;i<=o;i++){
		while(a[i].x>0){
			if(a[i].x>=a[r].x){
				a[i].x-=a[r].x;
				if(a[i].y!=a[r].y) cnt+=a[r].x;
				r--;
			}
			else{
				if(a[i].y!=a[r].y) cnt+=a[i].x;
				a[r].x-=a[i].x;
				a[i].x=0;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
