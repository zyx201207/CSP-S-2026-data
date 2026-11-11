#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans;
int n,m;
int a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			if(a[j]==i)cnt++;
		}
		cout<<cnt<<' ';
	}
	return 0;
}
