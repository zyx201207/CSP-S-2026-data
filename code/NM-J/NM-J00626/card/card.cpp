#include <bits/stdc++.h>
using namespace std;
long long f[500010];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
long long n,t,mid,s=0,m;
char r;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>f[i];
}
for(int i=1;i<=n;i++){
	if(f[i]!=f[n]){
		s++;
	}
}
if(m==1){
	cout<<n; 
}
if(m==2){
	if(f[n]==1){
		cout<<n<<" "<<s;
	}else{
		cout<<s<<" "<<n;
	}
}
return 0;
}



