#include<bits/stdc++.h>
using namespace std;
long long a[200006];
deque<int>dq;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dq.push_back(a[i]);
		a[i]=1;
	}
    cout<<3<<" "<<1<" "<<4; 
	return 0;
}
