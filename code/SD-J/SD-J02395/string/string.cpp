#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2e5+20;
ll n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	ll i=1,j=n,ans=0;
	while(i<j){
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				ans+=a[j];
			}
			else if(a[i]==a[j]){
				ans+=a[i];
			}
			else{
				ans+=a[i];
			}
		}
		if(a[i]>a[j]){
			a[i]-=a[j];
			a[j]=0;
			j--;
		}
		else if(a[i]==a[j]){
			a[i]=a[j]=0;
			i++,j--;
		}
		else{
			a[j]-=a[i],a[i]=0;
			i++;
		}
	}
	cout<<ans;
	return 0;
} 
//Trick||Treat!
/*
6
1 a
1 b
1 a
2 c
2 a
1 b
*/
