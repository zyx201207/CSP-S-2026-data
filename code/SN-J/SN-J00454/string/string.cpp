#include <bits/stdc++.h>
using namespace std;
int n;
long long cnt;
string ss,ss2;
int main(){
	freopen("string.in","a",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long xx;
		char aa;
		cin>>xx>>aa;
		for(long long l=1;l<=xx;l++){
			ss+=aa;
		}
	}
	for(long long ll=ss.size()-1;ll>=0;ll--)ss2+=ss[ll];
	for(long long ii=0;ii<ss.size();ii++){
		if(ss[ii]!=ss2[ii])cnt++;
	}
	cout<<cnt/2;
	return 0;
}
