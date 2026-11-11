#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
ll a[N],cnt;
char c[N];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		//sum+=a[i];
	}
	int l_id=1,r_id=n,LL=0,rr=0;
	while(l_id!=r_id){
		int lnum=a[l_id]-LL,rnum=a[r_id]-rr;
		if(lnum>rnum){
			if(c[r_id]!=c[l_id]){
				cnt+=rnum;
			}
			r_id--;
			rr=0;
			LL+=rnum;
		}else{
			if(c[r_id]!=c[l_id]){
				cnt+=lnum;
			}
			l_id++;
			LL=0;
			rr+=lnum;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
