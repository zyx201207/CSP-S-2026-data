#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,ans,o;
char c;
struct st{
	int a;
	char b;
};
st s[200005],u;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		
	}
	o=0;
	u.a=s[1].a;
	u.b=s[1].b;
	for(int i=1;;){
		for(int j=n;;){
			if(i==j){
				cout<<ans;
				return 0;
			} 
			if(o==0){
				if(u.b!=s[j].b){
					ans+=min(u.a,s[j].a);
					u.a=max(u.a,s[j].a)-min(u.a,s[j].a);
					if(u.a>s[j].a){
						o=0;
						j--;
					}else{
						o=1;
						u.b=s[j].b;
						i++;
					}
				}else{
					u.a=max(u.a,s[j].a)-min(u.a,s[j].a);
					if(u.a>s[j].a){
						o=0;
						j--;
					}else{
						o=1;
						u.b=s[j].b;
						i++;
					}
				}
			}else{
				if(u.b!=s[i].b){
					ans+=min(u.a,s[i].a);
					u.a=max(u.a,s[i].a)-min(u.a,s[i].a);
					if(u.a>s[i].a){
						o=1;
						i++;
					}else{
						o=0;
						u.b=s[i].b;
						j--;
					}
				}else{
					u.a=max(u.a,s[i].a)-min(u.a,s[i].a);
					if(u.a>s[i].a){
						o=1;
						i++;
					}else{
						o=0;
						u.b=s[i].b;
						j--;
					}
				}
			}
			if(i==j){
				cout<<ans;
				return 0;
			}
		}
	} 
	
} 

