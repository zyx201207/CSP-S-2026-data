#include<bits/stdc++.h>
using namespace std;
long long ans,l,r,n;
struct cc{
	int num;
	char c;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&s[i].num,&s[i].c);
	}
	for(l=1,r=n;l<=r;){
		if(s[l].c==s[r].c){
			if(s[l].num>s[r].num){
				s[l].num-=s[r].num;
				r--;
			}
			else if(s[l].num==s[r].num)l++,r--;
			else {
				s[r].num-=s[l].num;
				l++;
			}
		}
		else{
			if(s[l].num>s[r].num){
				s[l].num-=s[r].num;
				ans+=s[r].num;
				r--;
			}
			else if(s[l].num==s[r].num){
				ans+=s[r].num;
				l++,r--;
			}
			else {
				s[r].num-=s[l].num;
				ans+=s[l].num;
				l++;
			}
		}
	}
	cout<<ans;
}
