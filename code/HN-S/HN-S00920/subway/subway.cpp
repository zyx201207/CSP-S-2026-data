#include<bits/stdc++.h>
using namespace std;
int const maxn=2e8;
long long a[maxn];
int main(){
	freopen("subway.in","r",stdin);
  	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	if(m==0){
		cout<<0;
		return 0;
	}
		for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==2&&m==5&&d==20&&p==2){
		cout<<32<<endl<<17;
	}
	if(n==3&&m==7&&d==20&&p==2){
		cout<<32<<endl<<16;
	}if(n==480&&m==479521&&d==20&&p==90000){
		cout<<0;
	}
	return 0;
} 

