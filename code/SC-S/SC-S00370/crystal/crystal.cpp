#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0;
/*bool cmp(int x,int y){
	if(x>y) return x>y;
	return x<y;
}*/
int d(int x){ //比较从中间向左边加的个数 
	int cha,mm=a[(n+1)/2],cnt;
	cha+=(mm-a[x]);
	cnt+=1;
	if(cha==m) return cnt;
	else return d(x-1);
}
int dd(int y){  //比较从中间向右边加的个数
	int cha2,mmm=a[(n+1)/2],cntt;
	cha2+=(a[y]-mmm);
	cntt+=1;
	if(cha2==m) return cntt;
	else return dd(y+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long mid=a[(1+n)/2],da1,da2;
	for(int i=(1+n)/2;i>=1;i--){
		da1=d(i);
	}
	for(int i=(1+n)/2;i<=n;i++){
		da2=dd(i);
	}
	//cout<<da1<<" "<<da2<<endl;
	ans=max(da1,da2);
	cout<<ans/2;
	return 0;
}