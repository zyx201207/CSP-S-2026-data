#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char y;
};
bool flag;
int n;
long long ans;
node s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i].x>>s[i].y;
	int l=1,r=n;
	while(r>l){
		int a=s[l].x,b=s[r].x;
		if(s[l].y==s[r].y){
			if(a==b){
				l+=1;
				r-=1;
			}
			else if(a<b){
				s[r].x-=s[l].x;
				l+=1;
			}
			else{
				s[l].x-=s[r].x;
				r-=1;
			}
		}
		else{
			if(a==b){
				ans+=s[l].x;
				l+=1;
				r-=1;
			}
			else if(a<b){
				s[r].x-=s[l].x;
				ans+=s[l].x;
				l+=1;
			}
			else{
				s[l].x-=s[r].x;
				ans+=s[r].x;
				r-=1;
			}
		}
	}
	cout<<ans<<endl;
}
