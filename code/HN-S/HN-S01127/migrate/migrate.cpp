#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,s,b,f,k,l;
	cin>>c>>t;
	int z[t];
		for(int i=0;i<t;i++){
		cin>>s>>b;
		for(int r=0;r<s;r++){
			cin>>f;
		}
			if(s%2==0){
			k=(s-1)%b;
			z[i]+=k;
		}else{
			if((s-1)%b==0){
			l=(s-1)/b;
			z[i]+=l;
		}else{
			z[i]+=0;
		}
		}
	}
for(int i=0;i<t;i++){
	cout<<z[i];
	if(i<t-1){
		cout<<endl;
	}
}
return 0;
}
