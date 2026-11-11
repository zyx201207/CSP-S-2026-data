#include<bits/stdc++.h>
using namespace std;
long long n,sum,mid,ans;
struct P{
	long long x;
	char y;
}a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
	}
	long long i=0,j=n-1;
	while(i<j){
		if(a[i].x<a[j].x){
			if(a[i].y!=a[j].y){
				ans+=a[i].x;
			}
			a[j].x-=a[i].x;
			i++;
		}else if(a[i].x>a[j].x){
			if(a[i].y!=a[j].y){
				ans+=a[j].x;
			}
			a[i].x-=a[j].x;
			j--;
		}else{
			if(a[i].y!=a[j].y){
				ans+=a[i].x;
			}
			i++;j--;
		}
	}
	cout<<ans;
	return 0;
}
