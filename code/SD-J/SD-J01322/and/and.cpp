#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,l[200005],r[200005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> a >> b;
	for(long long i=1;i<=a;i++){
		cin >> l[i];
	}
	for(long long i=29;i>=0;i--){
		long long t=0;
		for(long long j=1;j<=a;j++){
			if(r[j]==0&&(l[j]&(1LL<<i))!=0){
				t++;
			}
		}
		if(t>=b){
			c+=(1LL<<i);
			for(long long j=1;j<=a;j++){
				if(r[j]==0&&(l[j]&(1LL<<i))!=0){
				}else{
					r[j]=1;
				}
			}
		}
	}
	cout << c;
	return 0;
}
