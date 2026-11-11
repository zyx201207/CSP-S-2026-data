#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int s;
	char c;
};node a[200010];
int ki,kj;
long long ans;
int i,j;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		ans+=a[i].s;
	}
	i=1;j=n;
	ki=a[i].s;kj=a[j].s;
	while(1){
		if(i==n+1||j==0)break;
		if(i==n&&j==1&&ki==kj&&a[i].c==a[j].c)break;
		if(a[i].c==a[j].c){
			if(ki>kj){
				ki-=kj;
				j--;
				kj=a[j].s;
			}
			else if(ki<kj){
				kj-=ki;
				i++;
				ki=a[i].s;
			}
			else{
				i++;j--;
				ki=a[i].s;
				kj=a[j].s;
			}
		}
		else{
			if(ki>kj){
				ans+=a[j].s;
				ki-=kj;
				j--;
				kj=a[j].s;
			}
			else if(a[i].s<a[j].s){
				ans+=a[i].s;
				kj-=ki;
				i++;
				ki=a[i].s;
			}
			else{
				ans+=a[i].s;
				i++;j--;
				ki=a[i].s;
				kj=a[j].s;
			}
		}
	}
	cout<<ans/4;
	return 0;
}
