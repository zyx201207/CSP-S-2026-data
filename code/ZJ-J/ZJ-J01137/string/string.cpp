#include<bits/stdc++.h>
using namespace std;
long long i,n,t,w,tt,ww,mi,ans,a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i]>>b[i];
	t=1;w=n;tt=a[1];ww=a[n];
	while(t<w){
		if(b[t]==b[w]){
			mi=min(tt,ww);
			tt-=mi;ww-=mi;
			if(tt==0){
				t++;
				tt=a[t];
			}
			if(ww==0){
				w--;
				ww=a[w];
			}
		}else{
			mi=min(tt,ww);
			ans+=mi;
			tt-=mi;ww-=mi;
			if(tt==0){
				t++;
				tt=a[t];
			}
			if(ww==0){
				w--;
				ww=a[w];
			}
		}
	}
	cout<<ans;
	return 0;
}

