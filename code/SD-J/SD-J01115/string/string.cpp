#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n;
struct node{
	LL z;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i].z>>a[i].c;
	}
	LL ans=0,cnt=0,sum=0;
	int l=1,r=n;
	while(l<=r){
		if(!ans){
			ans=a[l].z;
			l++;
		}
		if(!cnt){
			cnt=a[r].z;
			r--;
		}
		if(a[l-1].c!=a[r+1].c){
			sum+=min(ans,cnt);
		}
		if(cnt<ans){
			ans-=cnt;
			cnt=0;
		}else if(ans<cnt){
			cnt-=ans;
			ans=0;
		}else{
			ans=cnt=0;
		}
	}
	cout<<sum;
	return 0;
}
