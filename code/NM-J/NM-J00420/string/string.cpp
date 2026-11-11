#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long x=0;
	long long m=0;
	long long y=0;
	long long k=0;
	string vec;
	for(int i=0;i<n;i++){
		long long t=0;
		char q='0';
		cin>>t>>q;
		for(int j=0;j<t;j++){
			vec.push_back(q);
			
		}
		 x+=t;
			
		}
		if(x%2==0){
			m=x/2;
		}else{
			m=x+1;
			m/=2;
			}
			
	for(int i=x-1;i>m-1;i--){
		if(vec[i]==vec[y]){
			y++;
			continue;
			}else{
				y++;
				k++;
			}
		}
	cout<<k;
return 0;
	}


