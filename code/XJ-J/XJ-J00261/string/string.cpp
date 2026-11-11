#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char c1;
long long a,cnt,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a>>c1;
    	for(int j=1;j<=a;j++){
    	    s1+=c1;
	    }
	}
    for(int i=0;i<n;i++){
    	if(s1[i]!=s1[s1.size()-i-1]){
    		cnt++;
		}
	}
	cout<<cnt;	 
	return 0;
}