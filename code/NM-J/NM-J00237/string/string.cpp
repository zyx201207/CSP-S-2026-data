#include <bits/stdc++.h>
using namespace std;
struct word{
	long long a;
	char c;
}a[200010];
int top,n;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		long long b;
		char c,d;
		scanf("%lld%c%c",&b,&c,&c);
		if(a[top].c == c)
			a[top].a += b;
		else
			a[++top].a = b,a[top].c = c;
	}
	int l = 1,r = top;
	long long ans = 0;
	while(l < r){
		if(a[l].c == a[r].c){
			if(a[l].a >= a[r].a){
				a[l].a -= a[r].a;
				r--;
			}
			else{
				a[r].a -= a[l].a;
				l++;
			}
		}
		else{
			if(a[l].a >= a[r].a){
				ans += a[r].a;
				a[l].a -= a[r].a;
				r--;
			}
			else{
				ans += a[l].a;
				a[r].a -= a[l].a;
				l++;
			}
		}
	}
	printf("%lld",ans);
}
