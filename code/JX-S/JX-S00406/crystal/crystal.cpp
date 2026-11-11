#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	int b=0,c=INT_MAX;
	for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
			cnt+=abs(a[i]-a[j]);
        }
        //cout<<endl;
        if(cnt<c){
			b=i;
			c=cnt;
			//cout<<b<<" ";
		}
	}
	vector<int> d(n+1);
	for(int i=1;i<=n;i++){
		d[i]=abs(a[b]-a[i]);
    }
    //for(auto u:d){
	//	cout<<u<<" ";
	//}
    sort(d.begin()+1,d.end());
    int e=0,ans=0;
    for(int i=1;i<=n;i++){
		e+=d[i];
		if(e<=m){
			ans++;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
