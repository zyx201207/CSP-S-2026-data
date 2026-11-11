#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
struct node{
	int a;
	char c;
}s[N];
long long ans;
char last;
int num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>s[i].a;
		cin>>s[i].c;
	}
	
	for(int i=1,j=n; i<=n,j>=1,i<=j; ){
		if(s[i].c!=s[j].c){
			ans+=min(s[i].a,s[j].a);
		}
		if(s[i].a>s[j].a){
			s[i].a-=s[j].a;
			j--;
		}
		else if(s[i].a<s[j].a){
			s[j].a-=s[i].a;
			i++;
		}
		else{
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
