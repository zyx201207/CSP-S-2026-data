#include<bits/stdc++.h>
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);i--)
using namespace std;
const int N=2e5+10;
int n,m,a[N],p,p1,ans;
vector<int> v,v1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	L(i,1,n) cin>>a[i],v.push_back(a[i]);
	sort(a+1,a+1+n);
	R(i,31,0){
		int cnt=0;
		R(j,n,1) if((a[j]>>i)&1) cnt++;
		if(cnt>=m){
			p=i;
			break;
		}
	}
	
	R(i,p,0){
		int tcnt=0;
		for(int j:v){
			if((j>>i)&1) {
				tcnt++;
				v1.push_back(j);
			}
		}
		if(tcnt>=m) {
			ans+=(1<<i);
			v.clear();
			for(int j:v1) v.push_back(j);
			v1.clear();		
		}
	}
	cout<<ans;
	return 0;
}

