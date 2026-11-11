#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct node{
	long long a;
	char c;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
		cin>>s[i].c;
	}
	int lx=1,rx=n;
	long long la=s[1].a,ra=s[n].a;
	while(lx<=rx){
		if(la>=ra){
			if(s[lx].c!=s[rx].c){
				ans+=ra;
			}
			la-=ra;
			rx--;
			ra=s[rx].a;
		}
		else if(la<ra){
			if(s[lx].c!=s[rx].c){
				ans+=la;
			}
			ra-=la;
			lx++;
			la=s[lx].a;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
