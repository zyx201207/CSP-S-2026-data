#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101010],q,q1;
deque<long long> dq;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp.push_back(a[i]);
		if(a[i]==q || a[i]==q1){
			
		}
		if(a[i]==1) q=1;
		else q1=2;
	}
	return 0;
}
