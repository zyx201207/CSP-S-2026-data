#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=2e5+10;
int a[N];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m]<<endl;
	return 0;
}
