#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
unsigned long long cnt;
struct node{
	unsigned long long a;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(s[l].c==s[r].c){
			if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				r--;
			}else{
				if(s[l].a<s[r].a){
					s[r].a-=s[l].a;
					l++;
				}else{
					l++,r--;
				}
			}
		}else{
			if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				cnt+=s[r].a;
				r--;
			}else{
				if(s[l].a<s[r].a){
					s[r].a-=s[l].a;
					cnt+=s[l].a;
					l++;
				}else{
					cnt+=s[r].a;
					l++,r--;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
