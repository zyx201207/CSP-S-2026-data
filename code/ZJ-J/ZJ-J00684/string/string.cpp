#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[1000];
bool flag=1;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>m>>a[1];
	for(int i = 2;i <= n;i++){
		cin>>m>>a[i];
		if(a[i]!=a[i-1]){
			flag=0;
		}
	}
	if(flag){
		cout<<0;
	}
	else{
		cout<<m;
	}
	return 0;
}
