#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
long long L,wz,ans;
string b[200005];
void check(long long head,long long tail){
	long long hww=L+1-head,hwt=L+1-tail,i=0,j=0,lsbl;
	while(a[i]<=hwt) i++;
	while(a[j]<hww) j++;
	for (lsbl=i;lsbl<=j;lsbl++){
		if (i==j) {if (b[lsbl]!=b[wz])ans+=a[wz]-a[wz-1];}
		else {
			if (b[lsbl]!=b[wz]){
			if (lsbl==i) {
				ans+=(a[i]-hwt+1);
			}
			else if (lsbl==j) ans+=(hww-a[j-1]);
			else ans+=(a[lsbl]-a[lsbl-1]);
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		L+=a[i];
		a[i]+=a[i-1];
	}
	long long head=1,tail=1;
	while(tail<(L+1)/2){
		head=a[wz]+1;
		tail=a[++wz];
		head=min(head,(L+1)/2);
		tail=min(tail,(L+1)/2);
		check(head,tail);
	}
	cout<<ans;
}
