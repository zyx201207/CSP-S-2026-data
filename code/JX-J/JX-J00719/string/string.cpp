#include<bits/stdc++.h>
using namespace std;
string s;
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
	cin>>n;
	char c;
	int a;
	for(int j=1;j<=n;j++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	long long k=s.size()-1;
	for(int i=0;i<=k;i++,k--){
		if(s[i]!=s[k]){
                sum++;
		}
	}
	cout<<sum;
	return 0;
}
