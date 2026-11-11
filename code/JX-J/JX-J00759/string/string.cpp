#include <bits/stdc++.h>
using namespace std;
long long n,g,w,ans;
int main(){
	string s,s1;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
	    cin>>g>>s;
	    for(long long j=1;j<=g;j++){
		    s1=s1+s;
		}	
	}
	if(s1.size()%2==0) w=s1.size()/2;
	     else w=(s1.size()-1)/2;
	long long j=s1.size()-1;     
	for(long long i=0;i<w;i++){
	    if(s1[i]!=s1[j]) ans++;
	    j--;
	}
	cout<<ans;
    return 0;
}

