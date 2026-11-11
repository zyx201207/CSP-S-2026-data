#include<iostream>
#include<stdio.h>
using namespace std;
const int MAX=2e5+5;
typedef long long ll;
char c[MAX];
ll num[MAX];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
	}
	int lpos=1,rpos=n;
	while(lpos<rpos){
		if(c[lpos]!=c[rpos]){
			ans+=min(num[lpos],num[rpos]);
		}
		if(num[lpos]==num[rpos]){
			lpos++;
			rpos--;
		}
		else if(num[lpos]<num[rpos]){
			num[rpos]-=num[lpos];
			lpos++;
		}
		else{
			num[lpos]-=num[rpos];
			rpos--;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
