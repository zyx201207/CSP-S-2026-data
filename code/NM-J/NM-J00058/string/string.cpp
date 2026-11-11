#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;

struct node{
	ll num;
	char s;
}a[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].num >> a[i].s;
	}
	int it=n;
	for(int i=1;i<=n/2+2;i++){
		if(a[i].num==a[it].num&&a[i].s==a[it].s){
			it--;
			continue;
		}
		else if(a[i].num==a[it].num){
			ans+=a[it].num;
			a[it].num=0;
			it--;
			continue;
		}
		ll need=a[i].num;
		while(1){
			if(need<=0)break;
			if(a[it].num>need){
				a[it].num-=need;
				if(a[i].s!=a[it].s)ans+=need;
				break;
			}
			if(a[i].s==a[it].s){
				need-=a[it].num;
				it--;
				continue;
			}
			need-=a[it].num;
			ans+=a[it].num;
			a[it].num=0;
			it--;
		}
	}
	cout << ans;
	return 0;
}
