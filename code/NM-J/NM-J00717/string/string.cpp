#include <bits/stdc++.h>
using namespace std;
int n,ans,l,r,cnt,j;
int a[1000];
char b[1000];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cin>>b[i];

    }
    int z=0;
	for (int i=0;i<n;i++){
		for (int k=a[i];k>0;k--){
			s[z]=b[j];
			z+=1;
		}
		j+=1;
	}
	l=0;
    r=s.size()-cnt;
    while (l<=r) {

        cnt+=1;
        if (s[l]!=s[r]) ans+=1;
    }
    cout<<ans;
	return 0;
}
