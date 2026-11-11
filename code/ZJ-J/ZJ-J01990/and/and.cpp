#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[200005];
bool check(unsigned long long number){
	unsigned long long numb=1;
	while(1){
		if(numb==number){
			return true;
		}
		numb*=2;
	}
	return false;
}
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		cout<<a[i];
	}
	unsigned long long k=a[1];
	if(m==n){
		for(int i=2;i<=m;i++){
			k&=a[i];
		}
	}else{
		int asdf=0;
		if(check(k)){
			k=a[2];
			asdf++;
		}
		for(int i=2+asdf;i<=n;i++){
			if(check(a[i])){
				continue;
			}
			k&=a[i];
		}
	}
	cout<<k;
	return 0;
}