#include <bits/stdc++.h>
using namespace std;
#define int long long
int i,n,t,w,len[200010],ans;
char ch[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>len[i]>>ch[i];
	}
	t=1;w=n;
	while(t<w){
		if(ch[t]==ch[w]){
			if(len[t]>len[w]){
				len[t]-=len[w];
				len[w]=0;
				w--;
			}
			else if(len[t]==len[w]){
				len[t]=0;len[w]=0;
				t++;w--;
			}
			else{
				len[w]-=len[t];
				len[t]=0;
				t++;
			}
		}
		else{
			if(len[t]>len[w]){
				ans+=len[w];
				len[t]-=len[w];
				len[w]=0;
				w--;
			}
			else if(len[t]==len[w]){
				ans+=len[t];
				len[t]=0;len[w]=0;
				t++;w--;
			}
			else{
				ans+=len[t];
				len[w]-=len[t];
				len[t]=0;
				t++;
			}
		}
	}
	cout<<ans;
}
