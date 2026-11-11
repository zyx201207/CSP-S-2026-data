#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+1;
int n;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<ll>());
	// try 1 key for n loops of n decreasing
	ll ans=0;
	ll cur_r=0;
	ll cur_left=0;
	ll cur_ans=0;
	ll cur_num=a[1];//do we need pre- for 1st?
	// chu shi hua
	ll temp=m;
	for(int i=1;i<=n;i++){
		//a[i]<cur_num
		ll need=cur_num-a[i];
		if(need<=temp){//add it in
			temp-=need;
			cur_r=i;// r that satisfy
		}else{
			cur_left=temp;
			cur_ans=cur_r;//need calc later 
			ans=max(ans,cur_ans);//thats for first, need calc later
			break;
		}
	}
	for(int i=2;i<=n;i++){
		ll diff=a[i-1]-a[i];
		ll temp=cur_left+(cur_ans-1)*diff;
		cur_num=a[i];
		for(int j=cur_r+1;j<=n;j++){//start from next
			ll need=cur_num-a[j];
			if(need<=temp){
				temp-=need;
				cur_r=j;
			}else{
				cur_left=temp;
				cur_ans=cur_r-i+1;
				ans=max(ans,cur_ans);
				break;//copying code bef
			}
			// ah , when j==n it's not working. try a enforced version
			if(j==n){//this means it is suitable
				cur_left=temp;
				cur_ans=cur_r-i+1;
				ans=max(ans,cur_ans);
				break;//copying code bef
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 5

1 2 4 8 9


*/
