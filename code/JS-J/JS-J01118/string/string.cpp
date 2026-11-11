#include<iostream>
using namespace std;
using ll=long long;
const int N=2e5+7;
ll a[N],sum=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i]>>c[i];
	int i=1,j=n;
	while(i<j){
		ll x=a[i],y=a[j];
		if(c[i]!=c[j]) sum+=min(x,y);
		if(x>y) a[i]-=a[j],j--;
		else if(x<y) a[j]-=a[i],i++;
		else i++,j--;
	}
	cout<<sum<<endl;
	return 0;
}
