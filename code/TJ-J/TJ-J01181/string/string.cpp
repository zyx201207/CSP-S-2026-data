#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
}
    long long v=0;
    int l=1,r=n;
    while(l<r){
    	int f=min(a[l],a[r]);
    	if(c[l]!=c[r]){
    		v+=f;
		}
		a[l]-=f;
    	a[r]-=f;
		if(a[l]==0){
			l++;
		}
		if(a[r]==0){
			r--;
		}
	}
	cout<<v;
	return 0;
}
