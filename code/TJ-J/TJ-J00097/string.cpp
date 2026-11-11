#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,b,ans=0,x;
    char c;
    string s,r;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        for(int i=1;i<=x;i++){
            s+=c;
        }
    }
    b=s.size();
    	for(int i=1;i<=b;i++){
    		r[i]=s[b];
			b--;	
		}
		for(int i=1;i<=b;i++){
    		if(r[i]=s[i]){
    			ans++;
			}	
		}
	cout<<b-ans;
    return 0;
}
