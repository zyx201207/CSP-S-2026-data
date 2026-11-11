#include <bits/stdc++.h>
using namespace std;
long long n,a[200100],l1,l2,r1,r2,ans,m,t;
char c[200100];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l1=1;
	l2=1;
	r1=n;
	r2=a[r1];
	while(l1<r1||l1==r1&&l2<r2){
		if(l1>r1||l1==r1&&l2>=r2){
			break;
		}
		if(c[l1]!=c[r1]){
			ans++;
		}
		if(l2==a[l1]){
			l2=1;
			l1++;
		}
		else{
			l2++;
		}
		if(r2==1){
			r1--;
			r2=a[r1];
		}
		else{
			r2--;
		}
		//cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<'\n';
	}
	cout<<ans;
	return 0;
}
