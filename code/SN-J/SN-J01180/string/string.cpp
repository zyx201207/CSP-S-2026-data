#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace Vesperon{
	ll n,a,sum=0,num[26],mx=-LLONG_MAX,ans=0,mid;
	char c;
	vector<char> s;
	void work(){
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
		cin>>n; 
		for(int i=1;i<=n;i++){
			cin>>a>>c;
			for(int i=1;i<=a;i++){
				s.push_back(c);
			}
			sum+=a;
		}
		int mid=sum/2;
		for(int i=0;i<mid;i++){
			if(s[i]!=s[sum-i-1]) ans++;
		}
		cout<<ans;
	}
}
int main(){
	ios::sync_with_stdio(0);
	return Vesperon::work() ,0;
}
