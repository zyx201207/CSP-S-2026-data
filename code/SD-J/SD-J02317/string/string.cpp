#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long la,ra,ans;
long long n,a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	la=a[i];
	ra=a[n];
	while(1){
		if(i>=j) break;
		if(la>ra){
			la-=ra;
			if(c[i]!=c[j]) ans+=ra;
			j--;
			ra=a[j];
		}else if(la==ra){
			if(c[i]!=c[j]) ans+=la;
			i++,j--;
			la=a[i];
			ra=a[j];
		}else{
			ra-=la;
			if(c[i]!=c[j]) ans+=la;
			i++;
			la=a[i];
		}
	}
	cout<<ans;
	return 0;
} 
