#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[1000000000],br[1000000000],cr[1000000000];
char arr[10005];
char b,d;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,cnt=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>ar[i]>>arr[i];
	}
	for(int i=1;i<=a;i++){
		b=arr[i]*a+d;
		b=d;
		a--;
		br[i]=d%10;
		d=d/10;
		cr[i]=br[i];
		if(br[i]!=d%10) {
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
