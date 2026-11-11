#include<iostream>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n;
ll a[N];
char c[N];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]==a[j]){
			if(c[i]!=c[j]) ans+=a[i];
			i++,j--;
		}
		else if(a[i]<a[j]){
			if(c[i]!=c[j]) ans+=a[i];
			a[j]-=a[i];
			i++;
		}
		else{
			if(c[i]!=c[j]) ans+=a[j];
			a[i]-=a[j];
			j--;
		}
	}
	cout<<ans;
	return 0;
}
