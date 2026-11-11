#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200010],ans,sum,xum,f[30];
char c[200010];
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
    	sum+=a[i];
	} 
	for(int i=1;i<=n;i++){
		xum+=a[i];
		if(xum<=(sum/2)) f[int(c[i])-96]+=a[i];
		else{
			long long d;
			if(sum%2==0) d=(xum-(sum/2));
			else d=(xum-(sum/2+1));
			if(sum%2==0) f[int(c[i])-96]+=(a[i]-d);
			else f[int(c[i])-96]+=(a[i]-d-1);
			f[int(c[i])-96]-=d;
		}
	}
	for(int i=1;i<=26;i++) if(f[i]>0) ans+=f[i];
	cout<<ans<<'\n';
    return 0;
}
