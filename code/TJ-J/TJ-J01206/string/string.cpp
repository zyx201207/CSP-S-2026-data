#include<bits/stdc++.h> 
using namespace std;
int n,a[100005];
char c[100010];
long long len;
string l,r;
int main(){
		freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>c[i];
	len=len+a[i];
}
long long ans=len/2,la=0;
for(long long i=1;i<=len;i++){
for(int j=1;la+1<=ans&&j<=a[i];j++){
	la++;
	l+=c[i];
	
}
}
la=0;
for(int i=n;i>=1;i--){
for(int j=1;la+1<=ans&&j<=a[i];j++){
	la++;
	r+=c[i];
	
}
}
//cout<<l<<" "<<r<<endl;
for(int i=0;i<=len/2;i++){
	if(r[i]!=l[i])ans++;
	
}

cout<<ans-2;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
