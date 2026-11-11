#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int a;
	char b;
};
node s[N];
long long m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
	}
	int l=1,r=n;
	while(l<r){
		if(s[l].b==s[r].b){
			if(s[l].a==s[r].a){
				l++,r--;
			}else{
				int k=min(s[l].a,s[r].a);
				s[l].a-=k;
				s[r].a-=k;
			}
		}else{
			int k=min(s[l].a,s[r].a);
			s[l].a-=k;
			s[r].a-=k;
			m+=k;
		}
		if(s[l].a==0) l++;
		if(s[r].a==0) r--;
	}cout<<m;
	return 0;
} 
