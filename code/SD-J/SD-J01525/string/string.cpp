#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int d;
	char s;
}a[200005];
long long sum=0;
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].d>>a[i].s;
		sum+=a[i].d;
	}
	long long half=(sum+1)/2;
	long long front=1;
	long long rear=n;
	while (front<rear){
		if (a[front].s!=a[rear].s){
			if (a[front].d>=a[rear].d){
				cnt+=a[rear].d;
				a[front].d-=a[rear].d;
				a[rear].d=0;
				rear--;
			}else{
				cnt+=a[front].d;
				a[rear].d-=a[front].d;
				a[front].d=0;
				front++;
			}
		}else{
			if (a[front].d>=a[rear].d){
				a[front].d-=a[rear].d;
				a[rear].d=0;
				rear--;
			}else{
				a[rear].d-=a[front].d;
				a[front].d=0;
				front++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
