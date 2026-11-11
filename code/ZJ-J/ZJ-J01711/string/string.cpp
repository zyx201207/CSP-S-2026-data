#include<bits/stdc++.h>
#define AKCSPJ ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define int long long
using namespace std;//48pts
struct Node{
	int sum;
	char num;
}a[100010];
signed main(){
	AKCSPJ;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	int count=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].sum>>a[i].num;
		count+=a[i].sum;
	}
	int now1=1,now2=n,t1=1,t2=a[now2].sum;
	int ans=0;
//	cout<<now2<<endl;
	while(now1<=now2){
		char c1=a[now1].num,c2=a[now2].num;
		if(a[now1].sum==a[now2].sum&&t1==1&&t2==a[now2].sum){
			ans+=(a[now1].num==a[now2].num?0:a[now1].sum);
			now1++;
			now2--;
			t1=1;
			t2=a[now2].sum;
			continue;
		}
		if(c1!=c2)	ans++;
//		cout<<now1<<" "<<now2<<" "<<t1<<" "<<t2<<" "<<c1<<" "<<c2<<endl;
		t1++;
		t2--;
		if(t1>a[now1].sum){
			t1=1;
			now1++;
		}
		if(t2<1){
			now2--;
			t2=a[now2].sum;
		}
	}
	cout<<ans;
	return 0;
}
