#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c,m;
string s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%lld",&n);
    if(n==1){
    	cout<<0;
    	return 0;
	}
	else if(n==2){
		cout<<1;
		return 0;
	}
    else{
    	for(int i=1;i<=n;i++){
        	scanf("%lld%c",&a,&c);
        	for(int j=0;j<a;j++){
            	m=m^c;
        	}
        s[i]=m;
    	}
	}
    cout<<s.size();
    return 0;
}
