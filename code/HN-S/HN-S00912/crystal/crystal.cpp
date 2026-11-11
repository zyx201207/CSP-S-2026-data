#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b,c[100086],maxx=0;
	cin>>a>>b;
	for(long long i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a);
	for(long long i=0;i<a;i++){
		int x=0;
		for(long long j=0;j<b;j++){
			if(c[i]-c[j]>=b){
				x++;
			}
		}
		if(maxx<x){
			maxx=x;
		}
	}
	cout<<maxx;
	return 0; 
}
