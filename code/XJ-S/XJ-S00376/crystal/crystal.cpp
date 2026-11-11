#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005],s;
bool cmp(long long int x,long long int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long sum=n;
	for(int i=1 ; i<=n ; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1 ; i<=n ; i++){
		b[i]=a[1]-a[i];
		s+=b[i];
	}
	for(int i=1 ; i<=n ; i++){
		if(s<=m){
			break;
		}else{
		    sum--;
		    s-=(a[i]-a[i+1])*sum;
		}
	}
	cout << sum;
	return 0;
} 
