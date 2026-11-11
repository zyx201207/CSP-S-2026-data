#include<bits/stdc++.h>
using namespace std;
int n,a[200005],cnt1,cnt2,maxx;
string s[200005],s1;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n ;
	for(int i =1 ; i <= n ; i++)cin >> a[i] >> s[i];
	cnt1=1;
	cnt2=n;
	while(1){
		if(cnt1>=cnt2)break;
		if(s[cnt1]!=s[cnt2]){
			if(a[cnt1]>a[cnt2]){
				ans+=a[cnt2];
				a[cnt1]-=a[cnt2];
				cnt2--;
			}else if(a[cnt1]<a[cnt2]){
				ans+=a[cnt1];
				a[cnt2]-=a[cnt1];
				cnt1++;
			}else{
				ans+=a[cnt1];
				cnt2--;
				cnt1++;
			}
		}else{
			if(a[cnt1]>a[cnt2]){
				a[cnt1]-=a[cnt2];
				cnt2--;
			}else if(a[cnt1]<a[cnt2]){
				a[cnt2]-=a[cnt1];
				cnt1++;
			}else{
				cnt2--;
				cnt1++;
			}
		}
	}
	cout << ans;
	return 0 ;
}
