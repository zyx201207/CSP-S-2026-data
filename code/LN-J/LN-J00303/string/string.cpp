#include <bits/stdc++.h>
using namespace std;
long long a[20001]={};
char b[20001]={};
char all[2000001]={};
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >>a[i] >>b[i];
	}
	long long ll=0;
	for(int i=0;i<n;i++){
		for(__int128_t li=0;li<a[i];li++){
			all[ll+li]=b[i];
		}
		ll+=a[i];
	}
	for(long long i=0;i<ll;i++){
		if(all[i]!=all[ll-i]){
			ans++;
		}
	}
	cout <<ans/2;
	return 0;
}

