#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("and.in",'r',stdin);
	freopen("and.out",'w',stdout);
	int n,c,p,b=1;
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>p;
		a[i]==p;
	}
	p=1;
	for(int i=0;i<n;i++){
		for(int k=i;k<n;k++){
			if (b>=p) p=b;
			for(int j=k;j<c;j++){
				b=b&a[j];
		}
	}
	
}
	cout<<p;
	return 0;
}