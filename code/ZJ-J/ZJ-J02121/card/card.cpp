#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		if(a[n]==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2)
					ans++;
				else
					break;
			}
			cout<<n<<" "<<ans;
		}
		if(a[n]==2){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)
					ans++;
				else
					break;
			}
			cout<<ans<<" "<<n;
		}
    }
	return 0;
}
