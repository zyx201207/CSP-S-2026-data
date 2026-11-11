#include<bits/stdc++.h>
#define ll long long
#define bug(x) cout<<"----------"<<(x)<<"----------"<<endl;
using namespace std;
int n;
int a[200005],cnt=1;
char c[200005];
ll ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	while(cnt<n){
		if(a[cnt]>a[n]){
			if(c[cnt]!=c[n]){
				ans+=a[n];
			}
			a[cnt]-=a[n];
			n--;
		}else if(a[cnt]<a[n]){
			if(c[cnt]!=c[n]){
				ans+=a[cnt];
			}
			a[n]-=a[cnt];
			cnt++;
		}else{
			if(c[cnt]!=c[n]){
				ans+=a[n];
			}
			cnt++;
			n--;
		}
	}
	cout<<ans;
	return 0;
}
