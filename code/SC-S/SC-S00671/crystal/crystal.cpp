#include <iostream>
#include <stdio.h>
using namespace std;

int a[500005];
int b[500005];

void px(int st,int ed){
	int f=a[st];
	int s=st,e=ed;
	for(int i=st+1;i<=ed;i++){
		if(b[i]>f){
			a[e]=b[i];
			e--;
		}else{
			a[s]=b[i];
			s++;
		}
	}
	a[s]=f;
	for(int i=st;i<=ed;i++){
		b[i]=a[i];
	}
	for(int i=st;i<=s;i++){
		if(a[i]>a[i+1]){
			px(st,s);
			break;
		}
	}
	for(int i=s+1;i<ed;i++){
		if(a[i]>a[i+1]){
			px(s,ed);
			break;
		}
	}
}


int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=a[i];
	}
	px(1,n);
	int d=0,x=1;
	for(int i=2;i<=n;i++){
		if((i-1)*(a[i]-a[i-1])<=m){
			m-=(i-1)*(a[i]-a[i-1]);
		}else{
			cout << i-1;
			break;
		}
	}
	
	
	return 0;
 } 