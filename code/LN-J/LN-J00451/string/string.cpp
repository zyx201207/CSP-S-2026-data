#include<bits/stdc++.h>
using namespace std;
long long a[200001],top=0;
char c[200011];
int n;
int ans=0;
char s[1000010];
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        for(int j=1;j<=a[i];j++){
            top++;
            s[top]=c[i];
        }
	}
	for(int i=1;i<=top/2;i++){
        if(s[i]!=s[top-i+1])
            ans++;
	}
	cout<<ans;
	return 0;
}
