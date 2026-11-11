#include<bits/stdc++.h>
using namespace std;

int main(){
	fre("crystal.in","r",in);
	fre("crystal.out","w",out);
	int n,m,c,zj,b = 0;
	cin>>n>>m;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
    for(int i=0;i<n;i++){
		for(int j = 1;j<n;j++){
			if(a[j]<a[j-1]){
				c = a[j];
				a[j] = a[j-1];
				a[j-1] = c;
			}
		}
	}
	zj = a[n/2];
	for(int i = a[n/2];i>0;i++){
		m-=(zj-a[i]);
		if(m>0){
			b++;
		}
		else break;
    }
	cout<<b;
	return 0;
}