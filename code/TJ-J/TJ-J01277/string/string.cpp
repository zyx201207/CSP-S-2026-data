#include<bits/stdc++.h>
using namespace std;
struct d{
	int a;
	char c;
};
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	d s[n+1];
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	int i=1,j=n;
	long long ans=0;
	while(true){
		if(i>=j)break;
		int m=min(s[i].a,s[j].a);
		if(s[i].c==s[j].c){
			if(s[i].a==s[j].a){
				i++;j--;
			}
			if(s[i].a<s[j].a){
				i++;s[j].a-=m;
			}
			if(s[i].a>s[j].a){
				j--;s[i].a-=m;
			}
		}
		if(s[i].c!=s[j].c){
			if(s[i].a==s[j].a){
				i++;j--;
			}
			if(s[i].a<s[j].a){
				i++;s[j].a-=m;
			}
			if(s[i].a>s[j].a){
				j--;s[i].a-=m;
			}
			ans+=m;
		}
	}
	cout<<ans<<endl;
	return 0;
}
