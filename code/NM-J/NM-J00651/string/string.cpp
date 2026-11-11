#include<bits/stdc++.h> 
using namespace std;

int main(){
freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
string a,b;
long long n,m,p=0,q=0;
cin>>n;
for(long long i=0;i<n;i++){
	cin>>m>>a;
	for(long long i=0;i<m;i++){
	b=b+a;
	
	
}
	p+=m;
}
for(long long i=0;i<p/2;i++){
	if(b[i]!=b[p-1-i]){
	
	   q++;
	}
	
}
 cout<<q;

return 0;
}


