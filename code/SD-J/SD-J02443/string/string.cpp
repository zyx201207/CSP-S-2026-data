#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,o=0,z=0,a;
    string l,c;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>c;
    	o=o+a;
    	for(int j=1;j<=a;j++){
    		l=l+c;
		}
	}
	
	for(int i=0;i<o/2;i++){
		if(l[i]!=l[o-1-i]){
			z++;
		}
	}
	cout<<z;
	return 0;
}

