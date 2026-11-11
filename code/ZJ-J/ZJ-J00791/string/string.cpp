#include <bits/stdc++.h>
using namespace std;
struct node{
    int x;
	char id;	
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;

	for(int i = 1;i<=n;i++){
		cin>>a[i].x>>a[i].id;
	}
	int l = 1,r = n;
	int ll = a[l].x,rl = a[r].x;
	long long sum = 0;
	while(l<r){
		int sys = 0;
		if(ll>=rl){
			sys = 1;
		}
		if(a[l].id == a[r].id){
			if(sys == 1){
				ll -= rl;
				r--;
				rl = a[r].x;
				if(ll == 0){
					l++;
					ll = a[l].x;
				}
			}else{
				rl -= ll;
				l++;
				ll = a[l].x;		
			}
			continue;
		}
		if(sys == 1){
			sum += rl;
			ll -= rl;
			r--;
			rl = a[r].x;
			if(ll == 0){
				l++;
				ll = a[l].x;
			}
		}else{
			sum += ll;
			rl -= ll;
			l++;
			ll = a[l].x;
		}
		
	}
	cout<<sum;
	return 0;
}