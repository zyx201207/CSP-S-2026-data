#include<bits/stdc++.h>
using namespace std;
struct gai{
	long long s;
	char z;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long int sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i].s>>a[i].z;
	}
	int i=0,j=n-1;
	while(1){
		if(i>=j){
			cout<<sum;
			return 0;
		}
		if(a[i].z==a[j].z){
			if(a[i].s>a[j].s){
				a[i].s-=a[j].s;
				a[j].s=0;
				j--;
			}else if(a[i].s<a[j].s){
				a[j].s-=a[i].s;
				a[i].s=0;
				i++;
			}else{
				a[i].s=0;
				a[j].s=0;
				i++;
				j--; 
			}
		}else if(a[i].z!=a[j].z){
			if(a[i].s>a[j].s){
				a[i].s-=a[j].s;
				sum+=a[j].s;
				a[j].s=0;
				j--;
			}else if(a[i].s<a[j].s){
				a[j].s-=a[i].s;
				sum+=a[i].s;
				a[i].s=0;
				i++;
			}else{
				sum+=a[i].s;
				a[i].s=0;
				a[j].s=0;
				i++;
				j--;
			}
		}
	}
	
	return 0;
}
