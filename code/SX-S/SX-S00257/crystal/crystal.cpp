#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005],c[100005],b[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool f = true;
	int mvp = 0,o,r;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		b[a[i]]++;
		if(b[a[i]] > 1){
			f = false;
			if(b[a[i]] > mvp){
				mvp = b[a[i]];
				o = a[i];
				r = i;
			}
		}
	}
	sort(a+1,a+n+1);
	if(f){
		c[1] = 0;
		for(int i = 2;i <= n;i++){
			c[i] = a[i]-a[i-1];
		}
		int sum = 0,l = 0;
		for(int i = 1;i <= n;i++){
			sum+=c[i];
			l++;
			if(sum > m){
				sum-=c[i];
				l--;
				break;
			}
		}
		cout<<l;
	}
	else{

	}
	return 0;
}