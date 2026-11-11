#include<bits/stdc++.h>
using namespace std;
int l;
long long  a[10000004],n,zjz,sum;
struct zzx{
	string b;
}a1[100005];
int xsd,num;
int main(){
freopen("string.in","r",stdin);
freopen("string.out ","w",stdout);
cin>>n;
string s,a2;
for(long long i=1;i<=n;i++){
	cin>>a[i];
	cin>>a1[i].b ;
	sum+=a[i];
}
for(long long i=1;i<=n;i++){
	for(int j=1;j<=a[i];j++){
		s+=a1[i].b;
		a2+=a1[i].b;
	}
}

zjz=sum/2;
reverse(s.begin(),s.end());
for(long long i=0;i<=zjz;i++){
	if(s[i]!=a2[i]){
		++num;
	}

}
cout<<num;

/*for(int i=1;i<=sum++;i++){

}
for(int i=1;i<=n-1;i++){
if(a1[i].b==a1[i+1].b){
		xsd++;
	}
}
if(xsd==n-1){
	cout<<"0";
	return 0;
}

if(sum%2==0){
	zjz=sum/2;
}else{
	zjz=sum/2+1;
}
*/
}
