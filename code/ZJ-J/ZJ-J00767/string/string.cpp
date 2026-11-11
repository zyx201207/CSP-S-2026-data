#include<bits/stdc++.h>
#define ll long long
#define c first
#define a second
using namespace std;
ll n;
ll a;
ll cnt;
char c;
map<ll,pair<char,ll> >mp;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>c;
    	mp[i]={c,a};
	}
	int l=1,r=n;
	while(l<=r){
		if(mp[l].c == mp[r].c){
			if(mp[l].a > mp[r].a){
				mp[l].a-=mp[r].a;
				mp[r].a=0;
				r--;
			}else if(mp[l].a < mp[r].a){
				mp[r].a-=mp[l].a;
				mp[l].a=0;
				l++;
			}else{
				mp[r].a=0;
				mp[l].a=0;
				r--;
				l++;
			}
		}else{
			if(mp[l].a > mp[r].a){
				mp[l].a-=mp[r].a;
				cnt+=mp[r].a;
				mp[r].a=0;
				r--;
			}else if(mp[l].a < mp[r].a){
				mp[r].a-=mp[l].a;
				cnt+=mp[l].a;
				mp[l].a=0;
				l++;
			}else{
				cnt+=mp[r].a;
				mp[r].a=0;
				mp[l].a=0;
				r--;
				l++;
			}
		}
	}
	cout<<cnt;
    return 0;
}
