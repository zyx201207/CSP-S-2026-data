#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0;
	int m=0;
	int x=1;
	int z=0;
	long long y=0;
	long long g=0;
	cin>>n>>m;
	vector<long long >vec3;
	vector<long long >vec;
	long long vec1=0;
	vector<long long >vec2;
	for(int i=0;i<n;i++){
		int t=0;
		cin>>t;
		vec.push_back(t);
		vec3.push_back(t);
		}
	for(int i=0;i<n;i++){
		while(true){
			vec1=vec1+(vec[i]%2)*x;
			x*=10;
			vec[i]/=2;
			
			if(vec[i]==0){
				vec2.push_back(vec1);
				vec1=0;
				x=1;
				break;
				}
			}
		}
	if(m==1){
		
		for(int i=0;i<n;i++){
		g=max(g,vec3[i]);
		}
		cout<<g;
		
	}else if(m==n){
		for(int i=0;i<n;i++){
			y+=vec2[i];
		}
		x=1;
		for(int i=0;i<y;i++){
			if(y%10==n){
				z+=y%10*x;
				y/=10;
				x*=2;
			}else{
				x*=2;
			}
		}
		cout<<z;
	}
return 0;
	}
