#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls(i) i<<1
#define rs(i) i<<1|1
#define lowbit(x) x&-x
const int N=2e5+10;
const int M=5e5+10;
const int base=1e9+7;
const int base1=1e9+9;
const int mod=998244353;
int n;
int a[N];
string s;
int sum;
int ans;
int sum1;
int sum2;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    s=" ";
    for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		sum+=a[i];
		s=s+c;
	}
	int j=n;
	sum2=a[n];
	for(int i=1;i<=n;i++){
		while(a[i]){
			if(i>=j){
				cout<<ans;
				return 0;
			}
			if(s[i]!=s[j]){
				if(a[i]>=a[j]){
					a[i]-=a[j];
					ans+=a[j];
					j--;
				}else{
					a[j]-=a[i];
					ans+=a[i];
					a[i]=0;
				}
			}else{
				if(a[i]>=a[j]){
					a[i]-=a[j];
					j--;
				}else{
					a[j]-=a[i];
					a[i]=0;
				}
			}
		}
	}
	cout<<ans;
    return 0;
}
