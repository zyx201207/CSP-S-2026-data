//I used to recall the past
//我常常追忆过去 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int start=1,end=1;
	int nowcost=0;
	int ans=-1;
	while(end<n){
		int length=end-start+1;
		int newcost=nowcost+length*(a[end+1]-a[end]);
		if(newcost<=m){
			end++;
			nowcost=newcost;
		}
		else{
			while(1){
				start++;
				nowcost-=a[end]-a[start];
				length=end-start+1;
				newcost=nowcost+length*(a[end+1]-a[end]);
				if(newcost<=m){
					end++;
					nowcost=newcost;
					break;
				}
			}
		}
		ans=max(ans,end-start+1);
	}
	cout<<ans;
	return 0;
}
//finish at 14:46
//Oct31==Dec25?
//expect=100

