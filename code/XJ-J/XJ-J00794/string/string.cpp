#include <bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char b;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	node c[5];
	for(int i=0;i<n;i++){
		cin>>c[i].a>>c[i].b;
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		if(c[0].b==c[1].b){
			cout<<0;
		}else{
			cout<<1;
		}
	}
	return 0;
}