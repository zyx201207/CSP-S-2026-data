#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans=0;
struct str{
	char c;
	ll a;
}s[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	for(int i=1,j=n;i<j;){
		if(s[i].c==s[j].c){
			if(s[i].a==s[j].a){
				i++,j--;
			}else{
				if(s[i].a>s[j].a){
					s[i].a-=s[j].a;
					j--;
				}else{
					s[j].a-=s[i].a;
					i++;;
				}
			}
		}else{
			if(s[i].a==s[j].a){
				ans+=s[i].a;
				i++,j--;
			}else{
				if(s[i].a>s[j].a){
					ans+=s[j].a;
					s[i].a-=s[j].a;
					j--;
				}else{
					ans+=s[i].a;
					s[j].a-=s[i].a;
					i++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
