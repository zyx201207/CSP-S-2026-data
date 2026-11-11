#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=2e5+5;
int n,j;
ull a[N],k;
__int128 cnt1,cnt2,dc;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a[i-1]+=a[i];
			i--;
			n--;
		}
	}
	j=n+1;
	for(int i=1;i<=n;i++){
		cnt1+=a[i];
		while(cnt1>cnt2){
			if(cnt2+a[j-1]-k<cnt1){
				cnt2+=a[--j]-k;
				if(c[i]!=c[j]){
					dc+=a[j]-k;
				}
				k=0;
			}
			else{
				k=cnt1-cnt2;
				cnt2+=k;
				if(c[i]!=c[j-1]){
					dc+=k;
				}
			}
		}
	}
	cout<<ull(dc/(2ull));
	return 0;
}