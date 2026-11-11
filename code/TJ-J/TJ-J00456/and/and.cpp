#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
long long n,m,a[N],Max=-9999999999,cnt,num;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	cnt=a[1];
	for(int i=1;i<m;i++){
		cnt=cnt&a[i+1];
	}if(cnt >= Max){
		Max=cnt;
	}
	cout<<Max;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
