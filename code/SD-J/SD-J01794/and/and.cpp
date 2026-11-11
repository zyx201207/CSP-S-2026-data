#include<bits/stdc++.h>
using namespace std;
int n,a[200000],m,l;
int abc(int c,int w,int y){
	if(c>m){
		return l;
	}
	for(;w<n;w++){
		y=y&a[w];
		l=max(abc(c+1,w+1,y),y);
	}
}
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long  mx=-10000,i,l;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		mx=a[n];
	}
	else if(m==2){
		int a1,a2;
		for(a1=1;a1<=n;a1++){
			for(a2=a1+1;a2<=n;a2++){
				l=a[a1]&a[a2];
				mx=max(mx,l);
			}
		}
	}
	else if(m==n){
		mx=a[m];
		while(--m){
			mx=mx&a[m];
		}
	}
	else{
		int y=a[1];
		mx=abc(1,2,y);
	}
	cout<<mx;
	return 0;
} 
