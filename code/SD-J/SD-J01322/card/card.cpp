#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,l[500005],r[500005],n[500005],m[500005],x[500005],ans[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> a >> b;
	for(long long i=1;i<=a;i++){
		cin >> l[i];
		n[i]=1;
	}
	for(long long i=a;i>=1;i--){
		if(m[l[i]]==0){
			m[l[i]]=i;
			r[i]=1;
			x[i]=i+1;
		}else{
			x[i]=m[l[i]];
		}
	}
	for(long long i=1;i<=a;i++){
		if(r[i]==1){
			ans[l[i]]+=n[i];
		}
		n[x[i]]+=n[i];
	}
	for(long long i=1;i<=b;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
