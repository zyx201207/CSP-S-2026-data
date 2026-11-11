#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k[500011],k1[500011],a[200011];
ll f(ll pos){
	for(ll i=pos;i<=n;i++){
		k[i]=0;
	}
	return 0;
}
void d(){
	for(ll i=1;i<=n;i++){
		k[i]=k1[i];
	}
	return;
}
string s;
ll s1(int pos){
	for(ll i=pos;i<=s.size();i++){
		s[i]=0;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k1[i];
	}
	for(int i=1;i<=n;i++){
		d();
		for(int j=i;j<=n;j++){
			if(k[i]){
				if(s.find(k[i]+'0')!=string::npos){
					f(s.find(k[i]+'0'));
					s1(s.find(k[i]+'0'));
				}
				else s+=k[i]+'0';
				
			}
		}
		
	}
	return 0;
} 
