#include<bits/stdc++.h> 
using namespace std;
int n,m,ans,cnt,b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	vector<int> a(n+1),sum(n+1);
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=1;i<=n;i++){
	   if(a[i]==a[i-1])
	        ans++;
	}
	if(ans==n){
		cout<<a[1]*ans;
	    return 0;
	}
	if(m==2){
		if(a[n-1]==a[n])
		   cout<<ans<<" "<<0;
		else
		   cout<<n<<" "<<n-1;
		return 0;
	}
	sort(a.begin()+1,a.end()+1);
	for(int i=1;i<=m;i++)
	    cout<<i<<" ";
	return 0;
}
