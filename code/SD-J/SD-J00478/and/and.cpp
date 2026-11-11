#include<bits/stdc++.h>
using namespace std;
long long a[2000001]={0};
long long n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int s=a[0];
	for(long long i=0;i<m;i++){
		s=s&a[i];
	}
	cout<<s;
	return 0;//delete my freopen and all debug words;
}

