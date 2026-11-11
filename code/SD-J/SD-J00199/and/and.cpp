#include<bits/stdc++.h>
using namespace std;
long long b[1000000005];
void f(int x,int y){
	int g=x;
	int l=0;
	while(g>0){
		b[l]=g%2;
		g=g/2;
		l++;
	}
	g=y;
	l=0;
	while(g>0){
		if(b[l]==1&&g%2==1){
			b[l]=1;
		}
		else{
			b[l]=0;
		}
		g=g/2;
		l++;
	}
	long long e=1;
	for(int i=0;i<l;i++){
		y=b[i]*e;
		e=e*2;
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n,m;
	int a[n];
	int num=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		num=max(num,a[i]);
	}
	int c=n;
	int mum=0;
    for (int i=0;i<m;i++){
    	for (int j=0;j<n;j++){
    		f(a[i],num);
		}
	}
	cout<<num;
	return 0;
} 
