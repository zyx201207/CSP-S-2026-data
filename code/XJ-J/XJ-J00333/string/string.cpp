#include<bits/stdc++.h>
using namespace std;
struct t{
	int a;
	char b;
};
int n,cnt=0,num[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string w="";
    t s[200005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].b;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<s[i].a;j++){
			w+=s[i].b;
		}
	}
	cnt=0;
	for(int i=0;i<n;i++){
		for(int j=n;j>0;j--){
			if(w[i]!=w[j]){
				w[j]=w[i];
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}