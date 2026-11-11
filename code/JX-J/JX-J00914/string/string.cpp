#include<bits/stdc++.h>
using namespace std;
long long n,a[20005],sum=0,ans=0;
string s="";
char c;
int main(){
//  freopen("string.in","r",stdin);
 //freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        sum+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=c;
        }
	}
	if(sum%2==0){
        for(int i=1;i<=sum/2;i++){
            if(s[i]==s[sum-i]) continue;
            else {
                ans++;
            }
        }
	}
	else if(sum%2!=0){
        for(int i=1;i<=(sum-1)/2;i++){
            if(s[i]!=s[sum-i]) {
                ans++;
            }
        }
	}
	cout<<ans;
	return 0;
}
