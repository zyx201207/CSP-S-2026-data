#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100001];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int mx=-1;
	int c,d;
	for(int k=0;k<n;k++){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;i++){
			int s=a[i]&a[j];
			if(s>=mx){
				mx=s;
				c=i;
				d=j;
			}
		}
		}
		a[c]=mx;
		a[d]=0;
	}
	cout<<mx;
	return 0;
} 
