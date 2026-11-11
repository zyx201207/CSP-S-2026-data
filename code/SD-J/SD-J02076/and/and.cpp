#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=-1e9;
unsigned int a[200005],p[200005];
int n,m;
int flag=0;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=a[i]+p[i-1];
	}	
		if(m==n){
				for(int i=1;i<=n;i++){a[i]=a[i]&a[i-1];ans=a[i];
			}
		}
		else{
		
		for(int bn=1;bn<=n-m+1;bn++){
			for(int wn=1;wn<=m;wn++){
			a[wn]=a[wn-1]&a[wn];
			flag=a[wn];
			}
			ans=max(ans,flag);
		}
	}
	cout<<ans;
	return 0;
}
