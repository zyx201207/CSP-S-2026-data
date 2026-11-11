#include<bits/stdc++.h>
using namespace std;

const int N=500010;

long long a[N];
long long n,m;
long long mx ;
long long c,an;

long long s(long long x,long long y){
	long long ant=0;
	for(int i=x;i>0;i--){
		y-=a[x]-a[i];
		if(not(y))return ant;
		ant++;
	}
	return ant;
}

long long ef(long long c,long long h){
	return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m>100000000000){
		if(n<1000000000){
			for(int i=0;i<n;i++)cin>>a[i];
			sort(a,a+1);
		}else{
			cin>>a[0]>>a[1];
		}
		c=a[1]-a[0];
		m/=c;
		c=1;
		for(int i=0;i<m;i+=c){
			if(an>n){
				cout<<n;
				return 0;
			}
			an++;
			c++;
		}
		cout<<an+1;
		return 0;
	}
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+1);
	
	for(int i=0;i<n;i++)mx=max(mx,s(i,m));
	cout<<mx;
	
	return 0;
}