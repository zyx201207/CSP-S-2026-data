#include<bits/stdc++.h>
const int slen=2e5+10;
using namespace std;
struct info{
	long long a;
	char c;
}z[slen];
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	long long n,ans=0;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>z[i].a>>z[i].c;
	}
	int i=1,j=n;
	while(i<j){
		if(z[i].c!=z[j].c){
			if(z[i].a>z[j].a){
				z[i].a-=z[j].a;
				ans+=z[j].a;
				j--;
			}
			else if(z[i].a<z[j].a){
				z[j].a-=z[i].a;
				ans+=z[i].a;
				i++;
			}
			else{
				ans+=z[i].a;
				i++;j--;
			}
		}
		else{
			if(z[i].a>z[j].a){
				z[i].a-=z[j].a;
				j--;
			}
			else if(z[i].a<z[j].a){
				z[j].a-=z[i].a;
				i++;
			}
			else{
				i++;j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
