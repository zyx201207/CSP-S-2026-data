#include<bits/stdc++.h>
using namespace std;
int n,L,ans;
struct node{
	int a,l,r;
	char c;
}s[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		s[i].l=L+1;
		L+=s[i].a;
		s[i].r=L;
	}
	int mid=(L-1)/2+1,x;
	for(int i=1;i<=n;i++){
		if(mid>=s[i].l&&mid<=s[i].r){
			x=i;
			break;
		}
	}
	if(L&1){
		for(int i=1,j=n;i<=x,j>=x;){
			if(s[i].c!=s[j].c)ans+=min(s[i].a,s[j].a);
			if(s[i].a<=s[j].a){
				s[j].a=s[j].a-s[i].a;
				i++;
			}
			else{
				s[i].a=s[i].a-s[j].a;
				j--;
			}
		}
	}
	else{
		for(int i=1,j=n;i<=x,j>=x+1;){
			if(s[i].c!=s[j].c)ans+=min(s[i].a,s[j].a);
			if(s[i].a<=s[j].a){
				s[j].a=s[j].a-s[i].a;
				i++;
			}
			else{
				s[i].a=s[i].a-s[j].a;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}