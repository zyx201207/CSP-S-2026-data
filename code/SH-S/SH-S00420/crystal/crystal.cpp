#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,b,c[10009],z;
	cin>>a>>b;
	for(int i=0;i<a;i++)
		cin>>c[i];
	for(int i=0;i<a;i++)
		for(int j=i+1;j<a;j++)
			if(c[i]>c[j]){
				z=c[j];
				c[j]=c[i];
				c[i]=z;
			}
	int d=a/2;
	int e=a/2;
	for(int i=0;i<a;i++){
		if(b==0)
			break;
		if(c[d]-c[d-1]>c[e+1]-c[e]){
			b-=(c[e+1]-c[a/2]);
			e++;
		}
		else{
			b-=(c[a/2]-c[d-1]);
			d--;
		}
	}
	cout<<e-d+1;
	return 0;
}
