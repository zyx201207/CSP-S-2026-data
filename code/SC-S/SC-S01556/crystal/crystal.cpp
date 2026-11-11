#include<iostream>
using namespace std;
long long a[500005],m,p;
int n,ans=1,maxans,b;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= n;i++){
		b=a[i];
		for(int j = i-1;j >= 1;j--){
			p+=(b-a[j]);
			ans++;
			if(p>m){
				ans--;
				break;
			}
		}
		if(maxans<ans)maxans=ans;
		p=0;
		ans=1;
	}
	cout<<maxans;
	return 0;
}