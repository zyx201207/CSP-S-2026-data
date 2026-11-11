#include<bits/stdc++.h>
using namespace std;
long long n,l,r,cnt;
struct node{
	int a;
	char c;
}s[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	l=1;
	r=n;
	while(l<=r){
		if(s[l].a==s[r].a){
			if(s[l].c!=s[r].c){
				cnt+=s[l].a;
			}
			l++;
			r--;
		}
		else if(s[l].a>s[r].a){
			if(s[l].c!=s[r].c){
				cnt+=s[r].a;
			}
			s[l].a-=s[r].a;
			r--;
		}
		else{
			if(s[l].c!=s[r].c){
				cnt+=s[l].a;
			}
			s[r].a-=s[l].a;
			l++;;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
