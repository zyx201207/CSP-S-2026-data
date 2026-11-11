#include<bits/stdc++.h>
using namespace std;
long long a,b[200005],l,r,s[30],t;
char c[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)cin>>b[i]>>c[i];
	l=1,r=a;
	while(l<r){
		if(b[l]>b[r]){
			if(c[l]!=c[r]){
				s[1]+=b[r];
				t=1;
				while(s[t]>9){
					s[t+1]+=s[t]/10;
					s[t]%=10;
					t++;
				}
			}
			b[l]-=b[r];
			r--;
		}else{
			if(c[l]!=c[r]){
				s[1]+=b[l];
				t=1;
				while(s[t]>9){
					s[t+1]+=s[t]/10;
					s[t]%=10;
					t++;
				}
			}
			b[r]-=b[l];
			l++;
		}
	}t=20;
	while(!s[t]&&t>1) t--;
	while(t) cout<<s[t],t--;
	return 0; 
}
