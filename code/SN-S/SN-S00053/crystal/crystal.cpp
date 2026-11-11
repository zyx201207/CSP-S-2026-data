//crystal
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m;
ll ans=0,total=0;
ll a[N],p,q,r,cost=0;
bool cmp(const int a,const int b){
	return a<b;
}
int main(){
	ios::sync_with_stdio(false);
  	freopen("crystal.in","r",stdin);
  	freopen("crystal.out","w",stdout);
  	cin>>n>>m;
  	for(int i=1;i<=n;i++){
  		cin>>a[i];
	}
    sort(a+1,a+1+n,cmp);
    p=1;r=a[1];cost=0;total=1;
    for(int i=2;i<=n;i++){
    	q=a[i];
    	if(q==r)total++;
    	else{
    		ll need=(total)*(q-r);
    		while(need+cost>m&&total>0&&cost>0&&p!=i){
    			cost-=(r-a[p]);
    			p++;
    			need-=(q-r);
    			total--;
			}
			if(need+cost<=m)total++,cost+=need,r=q;
		}
		ans=max(ans,total);
	}
	cout<<ans<<endl;
	return 0;
} 
