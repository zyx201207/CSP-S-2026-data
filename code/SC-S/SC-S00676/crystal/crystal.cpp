#include<iostream>
using namespace std;
int n,m,a[555],mid,d,z,h,last=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[n/2+n%2]>a[0]&&a[n/2+n%2]<a[n-1]){
		mid=a[n/2+n%2-1];
	}
	d=mid-a[0];
	z=m-d;
	if(d<z){
		h=(mid-a[1])-z;
		for(int i=0;i<mid;i++){
			a[i]=mid;
			if(a[i]==mid){
				last++;
			}
		}
		if(a[n/2+n%2-1]==mid){
			last++;
		}
		cout<<last<<endl;
	}
	else{
		for(int i=0;i<a[n/2+n%2-1];i++){
			a[i]=mid;
			if(a[i-1]==mid){
				last++;
			}
		}
		cout<<last<<endl;
	}
	
	return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7