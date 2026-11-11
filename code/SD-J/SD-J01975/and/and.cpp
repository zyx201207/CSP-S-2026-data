#include <bits/stdc++.h>
using namespace std;
int n,m;
struct number{
	long long x;
	int sum,num;
}a[200005];
int sum1(int i){
	int ans=0;
	while(i){
		if(i%2==1)
			ans++;
		i/=2;
	}
	return ans; 
}
int sum2(int i){
	int ans=0;
	while(i){
		ans++;
		i/=2;
	}
	return ans; 
}
bool cmp(number a,number b){
	if(a.num!=b.num){
		if(a.sum!=b.sum)
			return a.sum>b.sum;	
		return a.num>b.num;
	}
	else if(a.x!=b.x)
		return a.x>b.x;
	else
		return a.sum>b.sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].sum=sum1(a[i].x);//1的个数 
		a[i].num=sum2(a[i].x);//二进制位数 
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[1].x;
	for(int i=2;i<=m;i++){
		ans&=a[i].x;
	}
	cout<<ans;
	return 0;
}

