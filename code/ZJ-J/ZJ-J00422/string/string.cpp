#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
struct point{
	ll len;
	char c;
};
int n;
point a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	ll cnt;
	for(int i=1;i<=n;i++){
		cin>>cnt>>a[i].c;
		a[i].len=a[i-1].len+cnt;
	}
	int left=1,right=n;
	ll gdl=0,gdr=a[n].len+1,ans=0;
	while(left<right){
		ll da=a[left].len-gdl,db=gdr-a[right-1].len-1;
		if(a[left].c!=a[right].c){
			ans+=min(da,db);
		}
		if(da==db){
			gdl=a[left].len,gdr=a[right-1].len+1;
			left++,right--;
		}
		else if(da>db){
			gdl+=db,gdr=a[right-1].len+1;
			right--;
		}
		else{
			gdl=a[left].len,gdr-=da;
			left++;
		}
	}
	cout<<ans;
	return 0;
}