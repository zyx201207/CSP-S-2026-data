#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout); 
    long long n,m,a=0,z=0;
    char c;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m>>c;
        for(int i=1;i<=m;i++){
            s[i]=c;
        }
    }
    long long l=s.size();
	for(int i=1;i<=l/2;i++){
		if(s[i]=s[l-i]) z=1;
		
	}
	if(z){
		cout<<a;
	}
		
    return 0;
}
