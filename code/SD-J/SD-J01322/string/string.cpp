#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,ans,l[200005];
char r[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> a;
	for(long long i=1;i<=a;i++){
		cin >> l[i] >> r[i];
		b+=l[i];
	}
	b/=2;
	c=a;
	d=0;
	while(b){
		e++;
		long long t=0;
		if(b<=l[e]){
			t=b;
			b=0;
		}else{
			t=l[e];
			b-=l[e];
		}
		while(t){
			if(t<=l[c]-d){
				d+=t;
				if(r[c]!=r[e]){
					ans+=t;
				}
				t=0;
			}else{
				if(r[c]!=r[e]){
					ans+=l[c]-d;
				}
				t-=l[c]-d;
				d=0;
				c--;
			}
		}
	}
	cout << ans;
	return 0;
}
