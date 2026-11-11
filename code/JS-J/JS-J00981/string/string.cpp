#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,cnt;
char c[N];
long long num[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>c[i]>>num[i];
	}
	int l=1,r=n;
	while(l<r){
		int mi=min(num[r],num[l]);
		if(c[l]!=c[r]) cnt+=mi;
		num[l]-=mi;
		num[r]-=mi;
		if(num[l]==0)l++;
		if(num[r]==0)r--;
		
	}
	cout<<cnt;
    return 0;
}
