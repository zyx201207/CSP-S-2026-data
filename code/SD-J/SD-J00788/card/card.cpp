#include<bits/stdc++.h>
using namespace std;
struct b{
	int begin;
	int end;
};
int main(){
	int a,b;
	cin>>a>>b;
	long long p[a+b],p1[128000]={0};
	for(int i=0;i<a;i++){
		cin>>p[i];
	}
	for(int j=1;j<b;j++){
		p[a]=j;
		for(int m=0;m<a+1;m++){
			if(p1[p[m]]==0){
				p1[p[m]]=m;
			}
			else{
				for(int i=m+1;i<a+1;i++){
					p[p1[p[m]]]=p[p1[p[m]]+i];
				}
			}
		}
	}
	for(int i=0;i<a+1;i++){
		if(p[i]==0){
			break;
		}
		cout<<p[i]<<' ';
	}
	return 0;
}
