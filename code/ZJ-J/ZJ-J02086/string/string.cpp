#include <bits/stdc++.h>
using namespace std;
long long n,num[200005], l[200005],dn;
char a[200005];
long long maxn;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i = 1; i <= n; ++i) {
		char u[4];
		scanf("%d",&num[i]);
		scanf("%s",u);
		l[i]=maxn;
		maxn+=num[i];
		
		
		a[i]=u[0];
	}
	if(maxn<=200000005) {
		string u=" ";
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= num[i]; j++) {
				u+=a[i];
			}
		}
		//cout<<u;
		for(int i = 1; i <= maxn/2; i++) {
			if(u[i]!=u[maxn-i+1]) {
				//cout<<u[i]<<" "<<u[maxn-i+1]<<endl;
				dn++;
			}
		}
	} else {
		long long js1=0,js2=0,j=n;
		for(int i = 1; i<=j; ) {
			if(js1<=js2) {
				if(js1==maxn/2) {
					break;
				}
				js1+=num[i];
				i++;
			}
			if(js2<js1) {
				js2+=num[j];
				j--;
			}
			//cout<<i <<" "<<j <<" "<<js1<<" "<<js2<<" "<<maxn<<endl;
			if(a[i-1]!=a[j+1]) {
				dn+=min(min(js1,maxn/2),min(js2,maxn/2))-max(js1-num[i-1],js2-num[j+1]);
				//cout<<dn<<endl;
			}
		}

	}
	cout<<dn;
	return 0;
}
/*
3
2 a
2 b
1 c

2
3 a
2 a

13
1 a
1 b
1 c
1 d
1 e
1 f
1 z
1 a
1 b
1 c
1 d
1 e
1 f
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


10
3 e
1 a
10 c
3 a
3 d
3 e
1 b
9 c
20 z
3 f
*/