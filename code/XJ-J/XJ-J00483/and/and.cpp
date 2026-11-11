#include<bits\stdc++.h>
using namespace std;
int main(){
    
    	        freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int m,n;
cin>>m>>n;
vector<int> x;
for(int i(0);i<m;i++){
	int c;
	cin>>c;
	x.push_back(c);
	
}
int max = -1;

for(int i(0);i<x.size();i++){
	for(int j(0);j<x.size();j++){
	if(x[i]||x[j]>max){
		max = (x[i]||x[j]);
	}
}
}
cout<<x[2];
}