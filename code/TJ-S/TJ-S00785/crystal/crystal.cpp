#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,r[1000000],u=1e9,p,o;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>r[i];
	}
	sort(r+1,r+1+a);
	d=a/2;
	e=b;
	for(int i=1;i<=a;i++){
		if(r[i]==r[d]){
			continue;
		}
		for(int j=1;j<=a;j++){
			if(r[j]==r[d]){
			continue;
		}
			if(r[d]-r[j]<=u and r[d]-r[j]>0){
				p=j;
				u=r[d];
			}
		}
		if(e-r[d]+r[p]>=0){
			o++;
			e-=r[d]+r[p];
		}else{
			cout<<o+1;
			return 0;
		}
	}
	cout<<o+1;
	return 0;
} 
