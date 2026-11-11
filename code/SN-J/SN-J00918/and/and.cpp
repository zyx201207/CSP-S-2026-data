#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int n,m;
int ma=0;
void fun(int b){
	m--;
	if(m<0){
		ma=max(ma,b);
		return ;
	}
	for(int i=1;i<=n;i++){
		fun(b&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	fun(1);
	cout<<ma;
	return 0;
}
