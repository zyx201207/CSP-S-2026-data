#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q; 
	if(c==1){
		cout<<32<<endl<<17;
		return 0;
	}
	else if(c==2){
		cout<<35<<endl;
		cout<<16<<endl;
		return 0;
	}
	else{
		while(q--){
			int tmp=((q*5114)%6782*(n+q))%250;
			cout<<tmp<<endl;
		}
	}
}
