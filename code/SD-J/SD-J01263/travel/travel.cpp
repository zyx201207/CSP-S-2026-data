#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans1=0,ans2=0,ans3=0,ans4=0;
	if(c1==c2){
		ans1=1;
		int a=stoi(s1),b=stoi(s2);
		if(a==b){
			ans2=1;
			char x=s1[2],y=s2[2];
			if((x<='C'&&y<='C')||(x>='D'&&y>='D')){
				ans3=1;
				if(x+1==y||y+1==x){
					ans4=1;
				}
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
