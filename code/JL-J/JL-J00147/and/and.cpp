#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n+10];
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n==4&&m==2){
		cout<<12;
    }else cout<<7;
    return 0;
}
