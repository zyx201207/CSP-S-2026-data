#include <iostream>
using namespace std;
struct k{
	long long n;
	char b;
};
k a[1000000];
int main(){
	int l,r=0;
	
	cin>>l;
	for(int i=0;i<l;i++){
		cin>>a[i].n>>a[i].b;
	}
	for(int j=0,m=l-1;j<=m;){
		if(a[j].n>a[m].n){
			if(a[j].b!=a[m].b){
				r+=a[m].n;
			}
			a[j].n-=a[m].n;
			m--;
		}
		else if(a[j].n<a[m].n){
			if(a[j].b!=a[m].b){
				r+=a[j].n;
			}
			a[m].n-=a[j].n;
			j++;
		}
		else{
			if(a[j].b!=a[m].b){
				r+=a[j].n;
			}
			j++;
			m--;
		}
	}
	cout<<r;
	return 0;
}
