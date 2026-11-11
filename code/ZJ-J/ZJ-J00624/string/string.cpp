#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int a;
	char c;
}s[500010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	long long ret=0;
	for(int i=1,j=n;i<j;i){
		if(s[i].a>s[j].a){
			s[i].a-=s[j].a;
			if(s[i].c!=s[j].c){
				ret+=s[j].a;
//				cout<<s[j].a<<endl;
			}
			j--;
		}
		else if(s[i].a<s[j].a){
			s[j].a-=s[i].a;
			if(s[i].c!=s[j].c){
				ret+=s[i].a;
			}
			i++;
		}
		else{
			if(s[i].c!=s[j].c){
				ret+=s[j].a;
			}
			i++,j--;
		}
//		cout<<i<<' '<<j<<' '<<ret<<endl;
	}
	cout<<ret;
	return 0;	
}
