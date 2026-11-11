#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N];
bool cmp(int q1,int q2){
	return q1>q2;
}
void mshi1(){
	int mx=-1;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
	}
	cout<<mx;
}
void mshin(){
	int mx=a[1];
	for(int i=2;i<=n;i++){
		mx=mx&a[i];
	}
	cout<<mx;
}
void mshin1(){
	int mx=0,ma=-1;
	for(int i=1;i<=n;i++){
		if(i==1)mx=a[2];
		else mx=a[1];
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			mx=mx&a[j];
		}
		ma=max(ma,mx);
	}
	cout<<ma;
}
void mshi2(){
	int mx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mx=max(mx,a[j]&a[i]);
		}
	}
	cout<<mx;
}
void nxiao20(){
	int mx;
	sort(a+1,a+n+1,cmp);
	mx=a[1];
	for(int i=2;i<=m;i++){
		mx=mx&a[i];
	}
	cout<<mx;
}
void zhib(){
	int mx;
	sort(a+1,a+n+1,cmp);
	mx=a[1];
	for(int i=2;i<=m;i++){
		mx=mx&a[i];
	}
	cout<<mx;
}
signed main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1)f=1;
	}
	if(!f)zhib();
	else if(m==1)mshi1();
	else if(m==n)mshin();
	else if(m==2)mshi2();
	else if(m==n-1)mshin1();
	else nxiao20();
	return 0;
} 
