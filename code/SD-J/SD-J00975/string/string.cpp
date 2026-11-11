#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
#define time cerr<<"\nTime is:"<<clock()
const int N=2e5+1;
ll n;
char s[N];
ll m[N];
ll cnt=0;
int main(){
	fin("string.in");
	fout("string.out");
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>s[i];
	}
	ll st=1,ed=n;
	while(st<ed){
		//if(st==179267||ed==179268) cerr<<cnt<<'\n';
		//cerr<<m[st]<<" "<<s[st]<<'\n'<<m[ed]<<" "<<s[ed]<<'\n';
		if(s[st]!=s[ed]){
			if(m[st]>m[ed]){
				cnt+=m[ed];
				m[st]-=m[ed];
				ed--;
			}
			else if(m[st]<m[ed]){
				cnt+=m[st];
				m[ed]-=m[st];
				st++;
			}
			else{
				cnt+=m[st];
				st++;
				ed++;
			}
		}
		else{
			if(m[st]>m[ed]){
				m[st]-=m[ed];
				ed--;
			}
			else if(m[st]<m[ed]){
				m[ed]-=m[st];
				st++;
			}
			else{
				st++;
				ed++;
			}
		}
		if(st==ed) return cout<<cnt,0;
		//cerr<<st<<" "<<ed<<" "<<cnt<<'\n';
	}
	cout<<cnt;
	return time,0;
}//C
