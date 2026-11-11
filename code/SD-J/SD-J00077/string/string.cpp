#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vector<pair<ll,char> > s(n);
	for(int i=0;i<n;i++){
		cin>>s[i].first>>s[i].second;
	}
	int i=0,j=n-1;
	while(i<=j){
		ll &a1=s[i].first,&a2=s[j].first;
		char c1=s[i].second,c2=s[j].second;
		int len=min(a1,a2);
		if(a1!=a2){
			if(a1>a2){
				a1-=a2;
				j--; 
			}
			else{
				a2-=a1;
				i++;
			}
		}
		else{
			i++;
			j--;
		}
		ans+=(c1==c2?0:len); 
	}
	cout<<ans<<"\n";
	return 0;
}
