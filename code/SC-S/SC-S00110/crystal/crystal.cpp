#include<bits/stdc++.h>
using namespace std;
long long c[100000000],j;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b,d=0,s1=0,s=0,z=-1;
	cin>>a>>b;
	
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	
	for(int i=2;i<a;i++){
		for(int q=0;q<a;q++){
		for(j=q;j<q+i;j++){
			s=c[j]+s;	


		}
		if(s%i==0){
			s=s/j;
			for(int v=0;v<i;v++){
				s1=abs(s-c[v])+s1;
		}
			if(s1==b and i>z){
				z=i;
		}
		}
		
		s=0;
		s1=0;
	}
	}
	cout<<z;
	return 0;
}