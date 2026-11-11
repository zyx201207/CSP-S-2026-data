#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=0x3f3f3f3f;
struct node{
	int a;
	char c;
}s[N];
unsigned long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	cin>>s[1].a>>s[1].c;
	char last=s[1].c;
	bool f=1;
	for(int i=2;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		if(last!=s[i].c){
			f=0;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	while(l<r){
		if(s[l].c==s[r].c){
			if(s[l].a<s[r].a){
				s[r].a-=s[l].a;
				l++;
			}else if(s[l].a==s[r].a){
				l++;
				r--;
			}else{
				s[l].a-=s[r].a;
				r--;
			}
		}else{
			if(s[l].a<s[r].a){
				s[r].a-=s[l].a;
				ans+=s[l].a;
				l++;
			}else if(s[l].a==s[r].a){
				ans+=s[l].a;
				l++;
				r--;
			}else{
				s[l].a-=s[r].a;
				ans+=s[r].a;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
} /*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/

