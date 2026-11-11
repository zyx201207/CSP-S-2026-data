#include<bits/stdc++.h>
using namespace std;
struct a1{
	int a;
	char c;
}ac[200000];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0,i,n,l=1,b;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ac[i].a>>ac[i].c;
	}
	while(n!=l){
		b=min(ac[l].a,ac[n].a);
		if(ac[n].c!=ac[l].c){
			ans+=b;
		}
		if(b==ac[l].a){
			ac[n].a-=ac[l].a;
			l++;
		}
		else{
			ac[l].a-=ac[n].a;
			n--;
		}
		
	}
	cout<<ans<<endl;
	return 0;
} 

