#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200010];
	char c[200010];
	long long ans=0;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		ans+=a[i];
	}
	long long p=(ans-ans%2)/2;
	long long d=0,e=0,t=0;
	long long w=n,u=0;
	for (int i=1;i<=n;i++){
		long long k=0;
		if (t+a[i]<=p){
			t+=a[i];
			k=a[i];
		}
		else{
			k=p-t;
			t=p;
		}
		while(k){
			if (a[w]-u<=k){
				k-=(a[w]-u);
				if (c[w]!=c[i]) d+=(a[w]-u);
				u=0;
				w--;
			}
			else{
				if (c[w]!=c[i]) d+=k;
				u+=k;
				k=0;
				break;
			}
		}
	}
	t=0;
	w=1;
	u=0;
	for (int i=n;i>=1;i--){
		long long k=0;
		if (t+a[i]<=p){
			t+=a[i];
			k=a[i];
		}
		else{
			k=p-t;
			t=p;
		}
		while(k){
			if (a[w]-u<=k){
				k-=(a[w]-u);
				if (c[w]!=c[i]) e+=(a[w]-u);
				u=0;
				w++;
			}
			else{
				if (c[w]!=c[i]) e+=k;
				u+=k;
				k=0;
				break;
			}
		}
	}
	if (d<=e) cout << d;
	else  cout << e;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
