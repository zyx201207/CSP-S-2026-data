#include<bits/stdc++.h>
using namespace std;
struct strings{
	long long m;
	char a;
};
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,l,r,ans=0;
	cin>>n;
	l=0;r=n-1;
	strings s[n+1];
	for(int i=0;i<n;i++) cin>>s[i].m>>s[i].a;
	while(l<r){
		if(s[l].m<s[r].m){
			if(s[l].a!=s[r].a){
				ans+=s[l].m;
			}
			s[r].m-=s[l++].m;
		}else if(s[l].m>s[r].m){
			if(s[l].a!=s[r].a){
				ans+=s[r].m;
			}
			s[l].m-=s[r--].m;
		}else{
			if(s[l].a!=s[r].a){
				ans+=s[r].m;
			}
			l++;
			r--;
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
