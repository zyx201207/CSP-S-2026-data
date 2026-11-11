#include<bits/stdc++.h>
using namespace std;
long long q,w;
const int a=200005;
long long e[a];
bool c(int x,int y){
	return  x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>q>>w;
	for(int i=0;i<q;i++){
		cin>>e[i];
	}
	sort(e,e+q,c);
	cout<<e[w-1];
	return 0;
}
