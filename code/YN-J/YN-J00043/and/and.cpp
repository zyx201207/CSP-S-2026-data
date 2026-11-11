#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int a1[a];
	for(int i=0;i<a;i++){
		cin>>a1[i];
	}
	for(int i=0;i<a;i++){
		int fz=0;
		for(int j=0;j<a;j++){
			if(a1[j]<a1[j-1]){
				fz=a1[j];
				a1[j]=a1[j-1];
				a1[j-1]=fz;
			}
		}
	}
	
	cout<<a1[a-b];
	return 0;
}
