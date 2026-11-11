#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,l,p;
ll m,a[N],la; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	p=1;
	for(int i=1;i<=n;i++){
		la+=a[i];
		while(m<a[i]*(i-p+1)-la){
			la-=a[p];
			p++;
		}
		l=max(l,i-p+1);
	}
	cout<<l;
	return 0;
}
//Oct31==Dec25?
/*
schedule
14:30-15:00 T1_t+w
15:00-15:45 T2_t+T3_t
15:45-16:45 T2_w
16:45-17:45 T3_w
17:45-18:15 T4_t+w

time table
14:39 KT1
*/
