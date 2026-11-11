#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=0,b,c,d;
	cin>>b>>c;
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
	stack<int> sta;
	for(int i=T;i<b;i++){
		sta.push(a[i]);
	}
	for(int i=1;i<=c;i++){
		cout<<b<<" ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
