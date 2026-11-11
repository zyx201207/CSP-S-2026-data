#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N=2*1e5+10;
int t;
struct node{
	int a;
	char b;
}s[N];
node s2[N];
int l;
int h=-0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	bool f=1;
	for(int i=1;i<=t;i++){
		cin>>s[i].a>>s[i].b;
		l+=s[i].a;
		if(s[i].b==s2[h].b){
			s2[h].a=s2[h].a+s[i].a;
			s2[h].b=s[i].b;
		}else {
			h++;
			s2[h].a=s[i].a;
			s2[h].b=s[i].b;
		}		
	}
	if(h==1){
		cout<<0<<endl;
		return 0;
	}
	int cnt1=0;
	int c1=1;
	int c2=h;
	while(c1<c2){
		if(s2[c1].b==s2[c2].b){
			if(s2[c1].a<s2[c2].a){
				s2[c2].a-=s2[c1].a;
				c1++;
			}else if(s2[c1].a>s2[c2].a){
				s2[c1].a-=s2[c2].a;
				c2--;
			}else{
				c1++;
				c2--;
			}
		}else{
			if(s2[c1].a<s2[c2].a){
				s2[c2].a-=s2[c1].a;
				cnt1+=s2[c1].a;
				c1++;				
			}else if(s2[c1].a>s2[c2].a){
				s2[c1].a-=s2[c2].a;
				cnt1+=s2[c2].a;
				c2--;
			}else{
				cnt1+=s2[c2].a;
				c1++;
				c2--;
			}
		}
			
	}
	cout<<cnt1<<endl;
	return 0;
}
