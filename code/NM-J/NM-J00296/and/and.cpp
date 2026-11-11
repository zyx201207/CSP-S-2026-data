#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b){
	if(abs(a-b)>=2) return a>b;
	else {
		if(a%2==0)return 0;
		else return 1;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cnt=a[1];
	for(int i=2;i<=m;i++){
		cnt&=a[i];
	}
	cout<<cnt;
	return 0;
}
