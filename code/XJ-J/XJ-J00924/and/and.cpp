#include<bits/stdc++.h>;
using namespace std;
long long int n,m,a,b,c,w;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>n[i];
		a=n[i];
		b=n[i+1];
		a%b=c;
		w=c;;
		if(w>a&b){
		c=w;	
		}
		if(w<a&b){
			n[i-1]&n[i]=c;
		}
	}
	cout<<c;
	return 0;
}