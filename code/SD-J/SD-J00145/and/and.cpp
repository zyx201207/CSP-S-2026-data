#include<bits/stdc++.h>
using namespace std;
const int MAX=2E5+10;
unsigned long long s,mmax;
int k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>s;
			mmax=max(mmax,s);
		}
		cout<<mmax;
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			cin>>s;
			mmax=mmax&s;
		}
		cout<<mmax;
	}
	
	return 0;
}
