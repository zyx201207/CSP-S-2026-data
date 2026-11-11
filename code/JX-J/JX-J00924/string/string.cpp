#include<bits/stdc++.h>
using namespace std;
int n,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a[n+5];
	char c[n+5];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    string l;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            l+=c[i];
        }
    }
    for(int i=0,j=l.size()-1;i<j;i++,j--){
        if(l[i]!=l[j]) s++;
    }
    cout<<s;
	return 0;
}
