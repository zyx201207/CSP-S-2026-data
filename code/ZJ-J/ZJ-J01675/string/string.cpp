#include<bits/stdc++.h>
using namespace std;
struct{
	long long w;
	char a;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].w;
		cin>>s[i].a;
	}
	long long z=0;
	int l=1;int r=n;
	while(l<r){
		if(s[l].a==s[r].a){
			if(s[l].w>s[r].w){
				s[l].w-=s[r].w;
				s[r].w=0;
				r--;
			}
			else{
				s[r].w-=s[l].w;
				s[l].w=0;
				l++;
			}
		}
		else{
			if(s[l].w>s[r].w){
				s[l].w-=s[r].w;
				z+=s[r].w;
				s[r].w=0;
				r--;
				
			}
			else{
				s[r].w-=s[l].w;
				z+=s[l].w;
				s[l].w=0;
				l++;
			
			}
//			cout<<s[r].w<<" "<<s[l].w<<" "<<z<<endl;
		}
	}
	cout<<z;
	return 0;
}
 
