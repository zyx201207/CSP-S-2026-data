#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long n,l=0,k=0;
	int a[200005];
	char c[200005];
	string S;
	cin>>n;
	for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
        for(int j=0;j<a[i];j++)S+=c[i];
	}
	int h=l/2;
	for(int i=h;i<l;i++){
        if(S[i]!=S[l-i-1])k+=1;
	}
	cout<<k;
	return 0;
}
