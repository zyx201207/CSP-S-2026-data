#include<bits/stdc++.h>
using namespace std;
/*====================*/
using lnt=long long;
/*====================*/
lnt arr[200500];
int n,m;
/*====================*/
bool Check(lnt num){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if((arr[i]&num)==num) cnt++;
	}
	return cnt>=m;
}
/*====================*/
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	lnt x=0;
	for(int i=30;i>=0;i--){
		if(Check(x+(1ll<<i))){
			x+=(1ll<<i);
		}
	}
	cout<<x<<'\n';
	return;
}
/*====================*/
int main(){
	freopen("and6.in","r",stdin);
	freopen("and6.out","w",stdout);
	int T=1; //cin>>T;
	while(T--) Solve();
	return 0;
}
