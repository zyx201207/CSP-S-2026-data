#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,l,r;
struct m{
	long long a;
	char b;
}c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>c[i].a>>c[i].b;
	}
	l=1;
	r=n;
	while(l<r){
		if(c[l].b!=c[r].b){
			if(c[l].a>c[r].a){
			ans+=c[r].a;
			c[l].a-=c[r].a;
			r--;
		}else{
			ans+=c[l].a;
			c[r].a-=c[l].a;
			l++;
		}
		}else{
			l++;
			r--;
		}

	}
	cout<<ans;
    return 0;
}
