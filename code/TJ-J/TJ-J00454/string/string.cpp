#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
char c[100001];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    string s="";
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
		for(int j=1; j<=a[i]; j++){
			s+=c[i];
		}
	}
	int l=0,r=s.size()-1,cnt=0;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt++;
		}
//		cout<<l<<" "<<r<<endl;
		l++,r--;
	}
	cout<<cnt;
}
