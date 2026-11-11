#include<bits/stdc++.h>
using namespace std;
int a[200010],ans;
string s,c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c;
    	if(n==1){
	    	ans=0;
		}
		if(n==2){
			if(c[i]!=c[i-1]){
				if(a[i]<=a[i-1]){
					ans=a[i];
				}
			}else{
				ans=0;
			}
		}
    	for(int j=1;j<=a[i];j++){
    		s+=c;
		}
	}
	cout<<ans;
	return 0;
}

