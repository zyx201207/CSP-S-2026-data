#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
long long n,a[N],b[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		b[i] = c - 'a';
	}
	long long ans=0,cnt1=0,cnt2=0,l=1,r=n;
	while(l<r){
		cnt1=a[l];
		cnt2=a[r];
		if(b[l] == b[r]){
			if(cnt1 == cnt2){
				l++;
				r--;
			}
			else if(cnt1 > cnt2){
				a[l]-=cnt2;
				r--;
			}
			else{
				l++;
				a[r]-=cnt1;
			}
		}
		else{
			if(cnt1 == cnt2){
				ans += cnt1;
				l++;
				r--;
			}
			else if(cnt1 > cnt2){
				ans+=cnt2;
				a[l]-=cnt2;
				r--;
			}
			else{
				ans+=cnt1;
				l++;
				a[r]-=cnt1;
			}
		}
		//cout<<l<<" :  "<<cnt1<<" "<<r<<" : "<<cnt2<<" "<<ans<<"\n";
	}
	cout<<ans;
    return 0;
}
