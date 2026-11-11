#include<bits/stdc++.h>
using namespace std;
int n;
struct q{
	int a;
	char c;
};
q s[200005];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	int i=1,j=n;
	while(i<j){
		if(s[i].a>s[j].a){
			if(s[i].c==s[j].c){
				s[i].a-=s[j].a;
				j--;
				continue;
			}else{
				s[i].a-=s[j].a;
				sum+=s[j].a;
				j--;
				continue;
			}
		}else if(s[i].a==s[j].a){
			if(s[i].c==s[j].c){
				i++;j--;
				continue;
			}else{
				
				sum+=s[i].a;i++;j--;
				continue;
			}
		}else{
			if(s[i].c==s[j].c){
				s[j].a-=s[i].a;
				i++;
				continue;
			}else{
				s[j].a-=s[i].a;
				sum+=s[i].a;
				i++;
				continue;
			}
		}
		
	}
	cout<<sum;
	return 0;
}
