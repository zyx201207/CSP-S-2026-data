#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct P{
	long long t;
	char x;
};
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	vector<P> f(n+1),l(n);
	for(int i=0;i<n;i++)
		cin>>l[i].t>>l[i].x;
	long long L3=0,R3=n-1,remL3=l[0].t,remR3=l[n-1].t,res3=0;
	while(L3!=R3){
		if(l[L3].x!=l[R3].x){
			if(remL3>remR3){
				remL3-=remR3;
				res3+=remR3;
				remR3=l[--R3].t;
			}
			if(remL3==remR3){
				res3+=remR3;
				remR3=l[--R3].t;
				remL3=l[++L3].t;
			}
			if(remL3<remR3){
				remR3-=remL3;
				res3+=remL3;
				remL3=l[++L3].t;
			} 
		}
		else{
			if(remL3>remR3){
				remL3-=remR3;
				remR3=l[--R3].t;
			}
			if(remL3==remR3){
				remR3=l[--R3].t;
				remL3=l[++L3].t;
			}
			if(remL3<remR3){
				remR3-=remL3;
				remL3=l[++L3].t;
			}
		}
	}
	cout<<ans;
}
