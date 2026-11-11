#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+100;
int n,a[N],len,ans;
char c[N];
string s;
bool b=1;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i>1&&c[i]!=c[i-1]) b=0;
	}
	if(b){
		cout<<'0';
		return 0;
	}
	int x=1,y=n;
	while(x<y){
		if(c[x]!=c[y]){
			if(a[x]>a[y]){
				ans+=a[y];
				a[x]-=a[y];
				y--;
			}else if(a[x]<a[y]){
				ans+=a[x];
				a[y]-=a[x];
				x++;
			}else if(a[x]==a[y]){
				ans+=a[x];
				x++,y--;
			}
		}else if(c[x]==c[y]){
			if(a[x]>a[y]){
				a[x]-=a[y];
				y--;
			}else if(a[x]<a[y]){
				a[y]-=a[x];
				x++;
			}else if(a[x]==a[y]){
				x++,y--;
			}
		}
	}
	cout<<ans;
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++) s[++len]=c[i];
	}
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1]) ans++;
	}
	cout<<ans;*/
	return 0;
}
