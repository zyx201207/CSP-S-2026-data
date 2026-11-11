#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
long long n,m;
long long a[N],s[N],ans;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	//cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long i=0,j=1;
	while(j<=n&&i<=n){
		if(a[j]*(j-i-1)-s[j-1]+s[i]<=m){
			ans=max(ans,j-i);
			j++;
		}else{
			i++;
		}
	}
	cout<<ans<<endl;
}
