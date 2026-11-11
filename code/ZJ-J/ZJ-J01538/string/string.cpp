#include <bits/stdc++.h>
using namespace std;
long long n[200010];
char m[200010];
int a;
long long b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1; i<=a; i++){
		cin>>n[i]>>m[i];
	}
	int x=1,y=a;
	while(y>x){
		long long p=min(n[x],n[y]);
		if(m[x]!=m[y]){
			b+=p;
		}
		n[x]-=p;
		n[y]-=p;
		if(n[x]==0){
			x++;
		}
		if(n[y]==0){
			y--;
		}
	}
	cout<<b;
}
