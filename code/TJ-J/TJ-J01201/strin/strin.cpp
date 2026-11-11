#include <bits/stdc++.h>
using namespace std;

long long n,a[200010],cnt;
string c,S=" ";

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c;
    	for(int j=1;j<=a[i];j++)
    	S+=c;
	}
	
	for(int z=1;z<=S.size()/2;z++)
		if(S[z]!=S[S.size()-z])cnt++;
		
	
	cout<<cnt;
	
    
    return 0;
    }
