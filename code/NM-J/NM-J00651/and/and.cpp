#include<bits/stdc++.h> 
using namespace std;

int main(){
freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
long long a,b,maxx=-1,k[10001],l;
cin>>a>>b;
for(int i=0;i<a;i++){
	cin>>k[i];
	if(maxx<k[i]){
		maxx=k[i];
		l=i;}
	}
	maxx=-1;
for(int i=0;i<a;i++){
	
	if(maxx<k[i]&&i!=l){
		maxx=k[i];
	}
	}
cout<<maxx;
return 0;
}


