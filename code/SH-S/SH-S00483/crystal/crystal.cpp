#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(int x,int y){
	return x<y;
}
int n,a[500005],cha[500005],m,f[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	int average=sum/n,maxn=1e18+1e9,sign;
	for(int i=1;i<=n;i++){
		if(maxn>=abs(average-a[i])){
			sign=i;
			maxn=abs(average-a[i]);
		}
	}	
	for(int i=1;i<sign;i++){
		cha[i]=abs(a[sign]-a[i]);
	} 
	sort(cha+1,cha+sign,cmp);
	int cnt=1;
	bool flag=0;
	while(m){
		for(int i=1;i<sign;i++){
			if(m>=cha[i]) m-=cha[i],cnt++;
			else{
				flag=1;
				break;
			}
		}
		if(flag==1){
			break;
		}
	}
	if(m>=cnt*(abs(a[sign+1]-a[sign]))){
		while(m){
			if(m>=cnt*(abs(a[sign+1]-a[sign]))) m-=cnt*(abs(a[sign+1]-a[sign])),sign++,cnt++;
			else break;
		}
	}
	cout<<cnt;
	return 0;
} 
