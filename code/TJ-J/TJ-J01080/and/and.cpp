#include<bits/stdc++.h>
using namespace std;
int m;
int n;
int awy;
int max=0;
int main(){
	cin>>n,m;
	cin>>s;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			awy=s[i] and s[-i];
			if(awy>max){
				max=awy;
			}
		}
	}
	cout<<max;
	return 0;
}
