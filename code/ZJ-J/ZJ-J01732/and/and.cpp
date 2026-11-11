#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
int n,m;
bool f=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	long long k=a[n];
	m-=1;
	int j=0;
	while(f==0&&j<n){
		k=a[n-j];
		j++;
		for(int i=n-1;m!=0&&i>=1;i--){
			if((k&a[i])==0){
				continue;
			}else{
				f=1;
				k=a[i]&k;
				m--;
			}
		}
	}
	
	if(!f){
		cout<<0;
		return 0;
	}
	cout<<k;
	return 0;
}
