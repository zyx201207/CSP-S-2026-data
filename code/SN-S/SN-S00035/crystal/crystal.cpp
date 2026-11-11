#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n=0,m=0,su=0,sn=0;
int a[500000] = {0};
int b[500000] = {0};
int c[500000] = {0};
long long s=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i = 0;i<n;i++){
		s = s+a[i];
	}
	int y =s/n;
	int f = s;
	int p =0;
	int tf =0;
	for(int i = 0;i<n;i++){
		a[i] = y-a[i];
	}
	int k =0;
	for(int i = 0;i<n;i++){
		if(a[i]==0){
			tf=1;
			i=n;
		}
		else{
			if(a[i]<0){
				k = 0-a[i]; 
			}
			if(k<f){
				f=k;
				p = i;
			}
		}
	}
	if(tf==0){
		y=a[p];
	}
	for(int i = 0;i<n;i++){
		c[i] = y-c[i];
	}
	for(int i = 0;i<n;i++){
		if(c[i]>=0){
			b[i] = c[i];
			su++;
		}
	}
	sort(b,b+su);
	for(int i = 0;i<su;i++){
		if(m>0){
			if(b[i]=0){
				sn++;	
			}
			else{
				if(b[i]<m){
					m-b[i];
					b[i]=0;
					sn++;
				}
			}	
		}
		else{
			i=su;
		}
	}
	if(sn == 1){
		cout<<0;
	}
	else{
		cout<<sn;
	}
	return 0;
} 
