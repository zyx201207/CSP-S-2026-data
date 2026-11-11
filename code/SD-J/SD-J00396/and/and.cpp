#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[20005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    int maxx=a[1];
    for(int i=1;i<=n;i++){
    	maxx=max(maxx,a[i]);
	}
	if(m==1) cout<<maxx<<endl;
	return 0;
}

