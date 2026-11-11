#include<bits/stdc++.h>
using namespace std;
#define _ long long
_ a,b[200001],ans;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	for(_ i=1;i<=a;i++){
		cin>>b[i]>>c[i];
	}
	_ l=1,r=a;
	while(l<r){
		if(b[l]<b[r]){
			if(c[l]!=c[r])ans+=b[l];
			b[r]-=b[l];
			++l;
		}
		else{
			if(c[l]!=c[r])ans+=b[r];
			b[l]-=b[r];
			--r;
		}
	}
	cout<<ans;
	return 0;
}