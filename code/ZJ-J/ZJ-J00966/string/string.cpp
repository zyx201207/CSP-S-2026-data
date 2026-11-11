#include <bits/stdc++.h>
using namespace std;

struct node{
	long long a;char c;
};

node a[400005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	long long li=1,ri=n;long long ans=0;
	while(li<ri){
		if(a[li].c==a[ri].c){
			if(a[li].a<a[ri].a){
				a[ri].a-=a[li].a;
				a[li].a=0;
				li++;
			}else{
				a[li].a-=a[ri].a;
				a[ri].a=0;
				ri--;
			}
		}else{
			if(a[li].a<a[ri].a){
				ans+=a[li].a;
				a[ri].a-=a[li].a;
				a[li].a=0;
				li++;
			}else{
				ans+=a[ri].a;
				a[li].a-=a[ri].a;
				a[ri].a=0;
				ri--;
			}
		}
	}
	cout<<ans;
	return 0;
}
