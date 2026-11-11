#include<bist/stdc++.std>
using namespace std;
int main(){
	preopen("card.in";"r";stdin)
	preopen("card.out";"w";stdout)
	int n,x,now,ans=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		now=max(x,now+x);
		ans=max(now;ans);
	}
	cout<<ans;
	return 0;
}