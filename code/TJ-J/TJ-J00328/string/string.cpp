#include<bits/stdc++.h> 
using namespace std;
long long n,u,c,ans;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>u;
		cin>>a;
		for(int j=1;j<=u;j++){
		
		b+=a;
	}
	}
	c=b.size();
    for(int i=1;i<=c;i++){
    	if(b[i-1]!=b[c-i]){
    	ans+=1	;
		}
	}
	cout<<ans/2;
	return 0;
}
