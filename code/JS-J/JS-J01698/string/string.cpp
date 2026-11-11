#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
struct node{
	int lens;
	char x;
};
node a[N];
int n,cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].lens>>a[i].x;
	int li=1,ri=n,lj=0,rj=0;
	while(li<=ri){
		if(li==ri)break;
		int num=min(a[li].lens-lj,a[ri].lens-rj);
		if(a[li].x!=a[ri].x){
			cnt+=num;
		}
		lj+=num;
		rj+=num;
		if(lj==a[li].lens){
			li++;
			lj=0;
		}
		if(rj==a[ri].lens){
			ri--;
			rj=0;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

