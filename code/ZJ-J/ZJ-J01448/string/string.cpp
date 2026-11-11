#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
long long ans,c;
struct str{
	long long a;
	char b;
} gm[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>gm[i].a>>gm[i].b;
	}
	for(int i = 1,j = n;i < j;){
		char b1 = gm[i].b;
		char b2 = gm[j].b;
		int a1 = gm[i].a;
		int a2 = gm[j].a;
		if(b1 != b2){
			c = 1;
		}
		if(a1 > a2){
			j--;
			gm[i].a -= a2;
			if(c) ans += a2;
		}else if(a1 < a2){
			i++;
			gm[j].a -= a1;
			if(c) ans += a1;
		}else{
			i++;
			j--;
			if(c) ans += a1;
		}
		c = 0;
	}
	cout<<ans;
	return 0;
}