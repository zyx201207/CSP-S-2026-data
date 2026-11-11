#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=n;i>0;i--)cout<<a[i]<<" ";
	return 0;
}
