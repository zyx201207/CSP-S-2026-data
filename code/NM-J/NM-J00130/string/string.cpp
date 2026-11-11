#include<bits/stdc++.h>
using namespace std;
vector<char> a;
char c1;
int c2;
int n;
long long ans;

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
	cin>>c2>>c1;
	for(int j=0;j<c2;j++)a.push_back(c1);
}
for(int i=0,j=a.size()-1;i+1!=j&&i!=j;i++,j--){
	if(a[i]!=a[j])ans++;
}
cout<<ans;
return 0;
}

