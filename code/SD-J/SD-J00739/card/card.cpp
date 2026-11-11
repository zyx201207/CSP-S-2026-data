#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N=3e5+10;
int s[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(m=1) cout<<n; 
	if(m=2){
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++){
			if(t[s[i]]==1){
				if(s[i]==1) ans1++;
				if(s[i]==2) ans2++;
			}
		}
		cout<<ans1<<" "<<ans2;
	} 


	return 0;
}

