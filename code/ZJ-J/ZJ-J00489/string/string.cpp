#include<bits/stdc++.h>
using namespace std;
int n,a[200200];
char c[200200],h,t;
long long s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	h=1,t=n;
	while(h<t){
		int m=min(a[h],a[t]);
		if(c[h]==c[t]){
			a[h]-=m;
			a[t]-=m;
			if(!a[h]) h++;
			if(!a[t]) t--;
		}else{
			a[h]-=m;
			a[t]-=m;
			s+=m;
			if(!a[h]) h++;
			if(!a[t]) t--;
		}
	}
	cout<<s;
}
