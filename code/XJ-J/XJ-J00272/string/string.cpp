#include<bits/stdc++.h>
using namespace std;
struct jg{
	long long s;
	char f;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string c="";
	long long l=0,z=0;
	cin>>n;
	jg d[n+1];
	for(long long i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		d[i].s=a;
		d[i].f=b;
	}
	int j=n,i=1,f=1,s=0;
	while(i<j){
		if(d[j].f!=d[i].f ){
			if(d[j].s>d[i].s ){
				z=z+d[i].s;
				d[j].s=d[j].s-d[i].s;
				 i++;
			}
			else if(d[i].s==d[j].s ){
				z=z+d[i].s;
				i++;
				j--;
			}
			else{
				d[i].s=d[i].s-d[j].s;
				z=z+d[j].s;
				j--;
			}
		}
		if(d[j].f==d[i].f){
			if(d[j].s>d[i].s ){
				d[j].s=d[j].s-d[i].s;
				 i++;
			}
			else if(d[i].s==d[j].s ){
				i++;
				j--;
			}
			else{
				d[i].s=d[i].s-d[j].s;
				j--;
			}
		}
	}
	cout<<z;
	return 0;
} 
