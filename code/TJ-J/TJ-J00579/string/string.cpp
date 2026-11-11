#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m1,m2;
long long xy;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i = 1;i <= n;i++){
    	cin>>a[i]>>c[i];
	}
	if (n%2==1){
		m1=m2=n/2+1;
	}
	else{
		m1=n/2;
		m2=m1+1;
	}
	if (c[m1]!=c[m2]){
		xy+=min(a[m1],a[m2]);
		c[m1]=c[m2];
	}
	for (int i = m2+1;i <= n;i++){
		if (c[i]==c[i-1]){
			if (c[m1-i+m2]==c[i]){
				xy+=abs(a[m1-i+m2]-a[i]);
				a[m1-i+m2]=a[i];
			}
			else {
				xy+=a[m1-i+m2];
				a[m1-i+m2]=a[i];
				c[m1-i+m2]=c[i];
			}
		}
		else
		{
			xy+=max(a[i],a[m1-i+m2]);
			a[i]=a[m1-i+m2];
			c[i]=c[m1-i+m2];
		}
	}
	cout<<xy;
	return 0;
}
