#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
long long c[100000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	b=b-1;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a+1,cmp);
	cout<<c[b];
	
	return 0;
}
