#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	long long ans=0;
	int hd=1,tl=n;
	long long hda=s[1].a;
	char hdc=s[1].c;
	long long tla=s[n].a;
	char tlc=s[n].c;
	while(hd<tl){
		int mn=min(hda,tla);
		hda-=mn;
		tla-=mn;
		if(hdc!=tlc){
			ans+=mn;
		}
		if(hda==0){
			hd++;
			hda=s[hd].a;
			hdc=s[hd].c;
		}
		if(tla==0){
			tl--;
			tla=s[tl].a;
			tlc=s[tl].c;
		}
	}
	cout<<ans;
	
	return 0;
}
