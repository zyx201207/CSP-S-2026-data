#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define i128 __int128
const int N=5e5+5;
int n;
ll m,a[N],S[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-(S[i]-S[i-x])<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[n+1]=12345678901000ll;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		S[i]=S[i-1]+a[i];
	int L=0,R=n;
	while(L<R){
		int mid=L+R+1>>1;
		if(check(mid)){
			L=mid;
		}else{
			R=mid-1;
		}
	}
	cout<<L;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
