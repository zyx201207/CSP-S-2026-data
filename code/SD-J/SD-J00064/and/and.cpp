#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],a1,a2,a3;
long long ans=0;
bool cmp(int x,int y){
	return x>y;
}
bool flag=true;
int main()
{
	freopen("and5.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<4){
			flag=false;
			if(a[i]==3)	a3++;
			else if(a[i]==2)	a2++;
			else a1++;
		}
	}
	sort(a+1,a+1+n,cmp);
	 if(flag){
		if(a3>=m){
			cout<<3;
			return 0;
		}
		if(a2+a3>=m){
			cout<<2;
		}
		else cout<<1;
		return 0;
	}
	//6-10
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
