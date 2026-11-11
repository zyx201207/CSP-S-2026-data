#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
long long fm=-1;
long long ans;
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>fm)fm=a[i];
		ans = ans & a[i];
	}
	if(m==1){
		cout<<fm;
	}
	else if(m==n){
	    cout<<ans;
	}
	else{
	    cout<<0;
	}
}
