#include<bits/stdc++.h>//jm99
#define endl '\n'//jm99
#define ll long long//jm99
using namespace std;//jm99
ll n,ans;//jm99
string s="";//jm99
int main(){//jm99
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);//jm99
	freopen("string.in","r",stdin);//jm99
	freopen("string.out","w",stdout);//jm99
	cin>>n;//jm99
    while(n--){//jm99
    	ll a;string c;//jm99
    	cin>>a>>c;//jm99
    	for(int i=0;i<a;i++)s+=c;//jm99
	}//jm99
    //cout<<s;
    ll size=s.size()/2,len=s.size();//jm99
    for(int i=0;i<size;i++){//jm99
    	if(s[i]!=s[s.size()-i-1])ans++;//jm99
    	//cout<<s[i]<<" "<<s[len-i-1]<<endl;
	}//jm99
	cout<<ans;//jm99
    return 0;//jm99
}//jm99
/*
3
2 a
2 b
1 c

2
2 a
3 a
*/
