#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int andd (int a,int b){
	int c=a&b;
	return c;
}
int main (){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,a[N],ma=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>ma){
			ma=a[i];
		}
	}
	if(m==1){
		cout<<ma;
	}
	if(m==n){
		int s=andd(a[1],a[2]);
		for(int i=2;i<n;i++){
			s=andd(s,a[i]);
		}
		cout<<s;
	}
	int mma=0,r;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			r=andd(a[i],a[j]);
			if(r>mma){
				mma=r;
			}
		}
	}
	cout<<mma;
	return 0;
}
