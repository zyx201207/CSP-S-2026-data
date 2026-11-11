#include<bits/stdc++.h>
using namespace std;
long long n,m,a,cnt=1;
string b,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    if(n==1){
    	cin>>n>>b;
    	cout<<0;
    	return 0;
	}else if(n==2){
		cin>>m>>b>>a>>c;
		if(b==c){
			cout<<0;
			return 0;
		}else{
			cout<<min(a,m);
			return 0;
		}  
	}else{
		for(int i=1;i<=n;i++){
			cin>>m>>b;
			if(m!=1){
				cnt=0;
			}
		}
		if(cnt=1){
			cout<<n/2;
			return 0;
		}
    }
	cout<<0;
    return 0;
} 

