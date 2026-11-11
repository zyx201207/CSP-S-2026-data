#include <bits/stdc++.h>
using namespace std;
//ios::sync_with_stdio(false);
int n,tmp,t;
long long s;
bool u;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a[n+2],g;
	char b[n+2],h;
	
	for(int i=0;i<n;i++){
		cin>>g;
		cin>>h;
		a[i]=g;
		b[i]=h;
	}
	if(a[0]>a[n-1]){
		u=1;
		tmp=a[0];
		t=a[n-1];
	}else if(a[0]<a[n-1]){
		u=0;
		tmp=a[n-1];
		t=a[0];
	}else{
		tmp=a[n-1];
		t=a[0];
	}
	for(int i=0;i<n/2;i++){
		while(tmp>=t){
		if(b[i]==b[n-i-1]){
			
		}else{
			s+=u?a[n-i-1]:a[i];
		}
		tmp-=u?a[n-i-1]:a[i];
		}
		tmp=-tmp;
		u=u?0:1;
		t=u?a[n-i-1]:a[i];
		if(tmp==0){
			tmp=u?a[n-i-2]:a[i+1];
		}
	}
	cout<<s;
	return 0;
}