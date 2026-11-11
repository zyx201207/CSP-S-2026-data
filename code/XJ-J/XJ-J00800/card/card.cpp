#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n,m,a[300005];
    queue<int>q;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int x=1;x<=m;x++){
	
    for(int i=1;i<n;i++){
    	for(int j=i+1;j<=n;j++){
    		if(a[i]==a[j]);
		}
	}
}
return 0;
}