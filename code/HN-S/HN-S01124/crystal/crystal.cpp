#include<bits/stdc++.h>
using namespace std;
const int MAXN=500001;
long long a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	t=a[2]-a[1];
	long long s=0;
	for(int i=1;;i++){
		s+=i;
		if(s*t>m){
			if(i>n){
				cout<<n;
				break;
			}
			else{
				cout<<i;
				break;
			}
		}
	}
	return 0;
}

